/*!
 * \file main.cpp
 * Основной алгоритм программы
 */
#include <QtCore/QCoreApplication>
#include "nodeType.h"
#include "patterncontainer.h"
#include <QDomNode>
#include <qfile.h>
#include <QMap>
#include <QTextCodec>

/*!
 * Возвращает карту соотвествия тега и типа
 * \return QMap ключ - тег, знаечние - тип
 */
QMap<QString,nodeType> & buildTagsMap()
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
 * Читает список шаблонов из xml файла
 * \param[in] filename имя файла содержащего список шаблонов
 * \return Контейнер шаблонов (память выделяется динамически!)
 * \throw char* строка с ошибкой
 */
patternContainer * readPatterns(QString &filename) throw (char *)
{
	patternContainer * data = new patternContainer();
	QMap<QString,nodeType> & tags = buildTagsMap();
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
			if( currentElement.tagName()==QString("default") && currentElement.hasAttribute("type") && tags.contains(currentElement.attribute("type")) );//если шаблон стандартный
			//data->addDefault(currentElement.attribute("type"), currentElement.text());
			
		}
		n = n.nextSibling();
	}
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec *tc=QTextCodec::codecForName("CP1251");
	QTextCodec::setCodecForCStrings(tc);

    return a.exec();
}
