/*!
 * \file main.cpp
 * Основной алгоритм программы
 */
#include <QtCore/QCoreApplication>
#include "nodeType.h"
#include "patterncontainer.h"
#include <tests.h>
#include <QDomNode>
#include <qfile.h>
#include <QMap>
#include <QTextCodec>
#include <clocale>

/*!
 *\mainpage explain-regexp Главная страница
 *\section Алгоритм
 main - реализует главный алгоритм программы
 *\subsection Шаблоны
 *QString - хранит стандартный шаблон.
 *\ref variant - хранит информация об альтернативном щаблоне .
 *\ref nodePattern - объединяет 2 поля перечисленных выше для пхранения списка шаблонов для определенного узла
 *\ref patternContainer - хранит список шаблонов для всех узлов.
 *\subsection Деревья
 *\ref node - абстрактный класс узла дерева, рекурсивную функцию для генерации описания дерева node::description
 *Для каждого узла определяется класс потомок, который переопределяет методы, возвращающие тип и тег, а также могут переопределить методы генерации описания
 *\ref nodeType - список типов узлов, i пункт списка имеет значение 2^i для реализации битовых флажков для допустимых типов шаблона.
 */

/*!
 * Возвращает карту соотвествия тега и типа
 * \return QMap ключ - тег, знаечние - тип
 */
const QMap<QString,nodeType> & buildTagsMap()
{
	static QMap<QString,nodeType> result;
	if(result.isEmpty())
	{
		result.insert("kmn", quantifier_mn );
		result.insert("km", quantifier_m );
		result.insert("kxn", quantifier_0n );
		result.insert("kmx", quantifier_m0 );
		result.insert("ks", quantifier_star );
		result.insert("kp", quantifier_plus );
		result.insert("kq", quantifier_question );
		result.insert("kmnp", quantifier_mn_plus );
		result.insert("kmp", quantifier_m_plus );
		result.insert("kxnp", quantifier_0n_plus );
		result.insert("kmxp", quantifier_m0_plus );
		result.insert("ksp", quantifier_star_plus );
		result.insert("kpp", quantifier_plus_plus );
		result.insert("kqp", quantifier_question_plus );
		result.insert("kmnq", quantifier_mn_question );
		result.insert("kmq", quantifier_m_question);
		result.insert("kxnq", quantifier_0n_question );
		result.insert("kmxq", quantifier_m0_question );
		result.insert("ksq", quantifier_star_question );
		result.insert("kpq", quantifier_plus_question );
		result.insert("kqq", quantifier_question_question );
		result.insert("con", concatenation );
		result.insert("or", oor );
		result.insert("g", group );
		result.insert("gq", group_question );
		result.insert("go", group_once );
		result.insert("cm", condition_mask );
		result.insert("cmy", condition_mask_yes );
		result.insert("cf", condition_forward );
		result.insert("cfn", condition_forward_negative );
		result.insert("cb", condition_back );
		result.insert("cbn", condition_back_negative );
		result.insert("mi", modifier_i );
		result.insert("ms", modifier_s );
		result.insert("mu", modifier_u );
		result.insert("mm", modifier_m );
		result.insert("ad", assert_d );
		result.insert("ac", assert_cap );
		result.insert("ab", assert_b );
		result.insert("abb", assert_b_big );
		result.insert("aab", assert_a_big );
		result.insert("azb", assert_z_big );
		result.insert("az", assert_z );
		result.insert("od", operand_d );
		result.insert("odb", operand_d_big );
		result.insert("os", operand_s );
		result.insert("osb", operand_s_big );
		result.insert("ow", operand_w );
		result.insert("owb", operand_w_big );
		result.insert("dot", dot );
		result.insert("sc", symbol_class );
		result.insert("scn", symbol_class_negative );
		result.insert("range", range );
		result.insert("symbol", symbol );
		result.insert("link", link );
		result.insert("oa", operand_a );
		result.insert("oe", operand_e );
		result.insert("on", operand_n );
		result.insert("ot", operand_t );
		result.insert("o8", operand_8 );
		result.insert("o16", operand_16 );
		result.insert("empty", empty );
		result.insert("t", otext );
	}
	return result;
}

/*!
 * Формирует структуру variant из QDomElement
 * \pre тег элемента не проверяется и атрибут type должен присутсвовать
 * \param[in] currentElement имя файла содержащего список шаблонов
 * \return альтернативный шаблон (структура \ref variant)
 */
variant QDomElementToVariant(const QDomElement &currentElement)
{
	const QMap<QString,nodeType> & tags = buildTagsMap();
	QMap<QString,nodeType>::iterator i;
	QRegExp re_type,re_parentType,re_child1Type,re_child2Type,re_child3Type,re_childType;	//реглярные выражения
	variant t_variant;//временная переменная для формированая альтернативного шаблона
	QString currentTag;
	nodeType currentType;

	//формируем структуру variant
	
	re_type.setPattern(currentElement.attribute("type"));//регулярное выражение для доступных типов
	re_parentType.setPattern(currentElement.attribute("parent-type"));//регулярное выражение для доступных типов родителя
	re_child1Type.setPattern(currentElement.attribute("child1-type"));//регулярное выражение для доступных первого ребенка
	re_child2Type.setPattern(currentElement.attribute("child2-type"));//регулярное выражение для доступных первого ребенка
	re_child3Type.setPattern(currentElement.attribute("child3-type"));//регулярное выражение для доступных первого ребенка
	re_childType.setPattern(currentElement.attribute("child-type"));//регулярное выражение для доступных любого ребенка

	t_variant.content = currentElement.attribute("content");//поле content заполнено
	t_variant.parentContent = currentElement.attribute("parent-content");//поле parent-content заполнено
	t_variant.childiContent[0] = currentElement.attribute("child1-content");//поле child1-content заполнено
	t_variant.childiContent[1] = currentElement.attribute("child2-content");//поле child2-content заполнено
	t_variant.childiContent[2] = currentElement.attribute("child3-content");//поле child3-content заполнено
	t_variant.form = currentElement.attribute("form");//поле form заполнено
	t_variant.m = currentElement.attribute("m");//поле m заполнено
	t_variant.n = currentElement.attribute("n");//поле n заполнено

	i=QMap<QString,nodeType>::iterator(tags.begin());//инициализуем итератор
	while(i != tags.end()) 
	{
		currentTag = i.key();
		currentType = i.value();

		//заполнение структуры type
		if(re_type.indexIn(currentTag)!=-1)//значит тег есть в описании атрибута type
			t_variant.type = t_variant.type | currentType;
		
		if(!re_parentType.isEmpty() && re_parentType.indexIn(currentTag)!=-1)//значит тег есть в описании атрибута parent-type
			t_variant.parentType = t_variant.parentType | currentType;

		if(!re_child1Type.isEmpty() && re_child1Type.indexIn(currentTag)!=-1)//значит тег есть в описании атрибута child1-type
			t_variant.childiType[0] = t_variant.childiType[0] | currentType;

		if(!re_child2Type.isEmpty() && re_child2Type.indexIn(currentTag)!=-1)//значит тег есть в описании атрибута child2-type
			t_variant.childiType[1] = t_variant.childiType[1] | currentType;

		if(!re_child3Type.isEmpty() && re_child3Type.indexIn(currentTag)!=-1)//значит тег есть в описании атрибута child3-type
			t_variant.childiType[2] = t_variant.childiType[2] | currentType;

		if(!re_childType.isEmpty() && re_childType.indexIn(currentTag)!=-1)//значит тег есть в описании атрибута child-type
			t_variant.childType = t_variant.childType | currentType;

		++i;
	} //битовые флажки для типов сформированы

	return t_variant;
}

/*!
 * Читает список шаблонов из xml файла
 * \param[in] filename имя файла содержащего список шаблонов
 * \return Контейнер шаблонов (память выделяется динамически!)
 * \throw char* строка с ошибкой
 */
patternContainer * readPatterns(QString &filename) throw (char *)
{
	patternContainer * data = new patternContainer();
	const QMap<QString,nodeType> & tags = buildTagsMap();
	QDomElement currentElement;

	QFile file(filename);					//открывает файл с шаблонами
	if (!file.open(QIODevice::ReadOnly))	//проверка
		throw "file open errror";			//выходим при ошибке

	QDomDocument domDocument;				//для разбора xml
	QString errorStr;						//текст ошибки xml
	int errorLine,errorColumn;

	if (!domDocument.setContent(&file, false, &errorStr, &errorLine, &errorColumn)) //устанавливаем контекст
	{
         throw qPrintable(QString("Parse error at line %1, column %2:\n%3").arg(errorLine).arg(errorColumn).arg(errorStr));//выталкиваем ошибку
	}

	QDomNode n = domDocument.firstChild();	//n - ребенок по порядку
	while (!n.isNull()) 
	{
		if (n.isElement()) 
		{
			currentElement = n.toElement();
			if( currentElement.tagName()==QString("default") && currentElement.hasAttribute("type") && tags.contains(currentElement.attribute("type")) )//если шаблон стандартный
				data->addDefault(currentElement.attribute("type"), currentElement.text());
			if( currentElement.tagName()==QString("variant") && currentElement.hasAttribute("type") )//если шаблон альтернативный
			{
				data->addVariant(QDomElementToVariant(currentElement));
			}
			
		}
		n = n.nextSibling();	//следущий ребенок
	}
	return data;
}

/*!
 *\brief Проверяет строку на наличие лишних знаков препинания
 * Удаляет двойные пробелы, запятые, ставит пробелы между подряд идущими скобками.
 *\param[in,out] str обрабатываемая строка
 */
void postprocessing(QString * str)
{

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	
	//настройка языка и консоли
    QTextCodec *tc=QTextCodec::codecForName("windows-1251");
	QTextCodec::setCodecForCStrings(tc);
	QTextCodec::setCodecForLocale(tc);
	setlocale( LC_ALL, "Russian_Russia.1251" );
	
	try
	{
		//запуск тестов
		tests t1;
		QTest::qExec(&t1);
	}
	catch(char * s)
	{
		qDebug("EXEPTION: %s!",s); 
	}

    return a.exec();
}
