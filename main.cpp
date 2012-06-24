/*!
 * \file main.cpp
 * �������� �������� ���������
 */
#include <QtCore/QCoreApplication>
#include "nodeType.h"
#include "patterncontainer.h"
#include "tests.h"
#include <QDomNode>
#include <qfile.h>
#include <QMap>
#include <QTextCodec>
#include <clocale>


/*!
 *\mainpage explain-regexp ������� ��������
 *\section ��������
 main - ��������� ������� �������� ���������
 *\subsection �������
 *QString - ������ ����������� ������.
 *\ref variant - ������ ���������� �� �������������� ������� .
 *\ref nodePattern - ���������� 2 ���� ������������� ���� ��� ��������� ������ �������� ��� ������������� ����
 *\ref patternContainer - ������ ������ �������� ��� ���� �����.
 *\subsection �������
 *\ref node - ����������� ����� ���� ������, ����������� ������� ��� ��������� �������� ������ node::description
 *��� ������� ���� ������������ ����� �������, ������� �������������� ������, ������������ ��� � ���, � ����� ����� �������������� ������ ��������� ��������
 *\ref nodeType - ������ ����� �����, i ����� ������ ����� �������� 2^i ��� ���������� ������� ������� ��� ���������� ����� �������.
 */

//���,���,�������1,�������2;
//"kmn",quantifier_mn,"m","n";
//"km",quantifier_m,"m";
//"kxn",quantifier_0n,"n";
//"kmx",quantifier_m0,"m";
//"ks",quantifier_star;
//"kp",quantifier_plus;
//"kq",quantifier_question;
//"kmnp",quantifier_mn_plus,"m","n";
//"kmp",quantifier_m_plus,"m";
//"kxnp",quantifier_0n_plus,"n";
//"kmxp",quantifier_m0_plus,"m";
//"ksp",quantifier_star_plus;
//"kpp",quantifier_plus_plus;
//"kqp",quantifier_question_plus;
//"kmnq",quantifier_mn_question,"m","n";
//"kmq", quantifier_m_question,"m";
//"kxnq",quantifier_0n_question,"n";
//"kmxq",quantifier_m0_question,"m";
//"ksq",quantifier_star_question;
//"kpq",quantifier_plus_question;
//"kqq",quantifier_question_question;
//"con",concatenation;
//"or",oor;
//"g",group;
//"gq",group_question;
//"go",group_once;
//"cm",condition_mask;
//"cmy",condition_mask_yes;
//"cf",condition_forward;
//"cfn",condition_forward_negative;
//"cb",condition_back;
//"cbn",condition_back_negative;
//"mi",modifier_i;
//"ms",modifier_s;
//"mu",modifier_u;
//"mm",modifier_m;
//"ad",assert_d;
//"ac",assert_cap;
//"ab",assert_b;
//"abb",assert_b_big;
//"aab",assert_a_big;
//"azb",assert_z_big;
//"az",assert_z;
//"od",operand_d;
//"odb",operand_d_big;
//"os",operand_s;
//"osb",operand_s_big;
//"ow",operand_w;
//"owb",operand_w_big;
//"dot",dot;
//"sc",symbol_class,"text";
//"scn",symbol_class_negative,"text";
//"range",range,"start","end";
//"symbol",symbol,"text";
//"link",link,"n";
//"oa",operand_a;
//"oe",operand_e;
//"on",operand_n;
//"ot",operand_t;
//"o8",operand_8,"n";
//"o16",operand_16,"n";
//"empty",empty;
//"t",otext,"text";

/*!
 * ���������� ����� ����������� ���� � ����
 * \return QMap ���� - ���, �������� - ���
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
 * ��������� ��������� variant �� QDomElement
 * \pre ��� �������� �� ����������� � ������� type ������ �������������
 * \param[in] currentElement ��� ����� ����������� ������ ��������
 * \return �������������� ������ (��������� \ref variant)
 */
variant QDomElementToVariant(const QDomElement &currentElement)
{
	const QMap<QString,nodeType> & tags = buildTagsMap();
	QMap<QString,nodeType>::iterator i;
	QStringList re_type,re_parentType,re_child1Type,re_child2Type,re_child3Type,re_childType;	//������ ���������� �����
	variant t_variant;//��������� ���������� ��� ������������ ��������������� �������
	QString currentTag;
	nodeType currentType;

	//��������� ��������� variant
	
	re_type = currentElement.attribute("type").split('|');//���������� ��������� ��� ��������� �����
	re_parentType = currentElement.attribute("parent-type").split('|');//���������� ��������� ��� ��������� ����� ��������
	re_child1Type = currentElement.attribute("child1-type").split('|');//���������� ��������� ��� ��������� ������� �������
	re_child2Type = currentElement.attribute("child2-type").split('|');//���������� ��������� ��� ��������� ������� �������
	re_child3Type = currentElement.attribute("child3-type").split('|');//���������� ��������� ��� ��������� ������� �������
	re_childType = currentElement.attribute("child-type").split('|');//���������� ��������� ��� ��������� ������ �������

	t_variant.content = currentElement.attribute("content");//���� content ���������
	t_variant.parentContent = currentElement.attribute("parent-content");//���� parent-content ���������
	t_variant.childiContent << currentElement.attribute("child1-content");//���� child1-content ���������
	t_variant.childiContent << currentElement.attribute("child2-content");//���� child2-content ���������
	t_variant.childiContent << currentElement.attribute("child3-content");//���� child3-content ���������
	t_variant.form = currentElement.attribute("form");//���� form ���������
	t_variant.m = currentElement.attribute("m");//���� m ���������
	t_variant.n = currentElement.attribute("n");//���� n ���������
	t_variant.pattern = currentElement.text();

	i=QMap<QString,nodeType>::iterator(tags.begin());//������������ ��������
	while(i != tags.end()) 
	{
		currentTag = i.key();
		currentType = i.value();

		//���������� ��������� type
		if(re_type.indexOf(currentTag)!=-1)//������ ��� ���� � �������� �������� type
			t_variant.type = t_variant.type | currentType;
		
		if(!re_parentType.isEmpty() && re_parentType.indexOf(currentTag)!=-1)//������ ��� ���� � �������� �������� parent-type
			t_variant.parentType = t_variant.parentType | currentType;

		if(!re_child1Type.isEmpty() && re_child1Type.indexOf(currentTag)!=-1)//������ ��� ���� � �������� �������� child1-type
			t_variant.childiType[0] = t_variant.childiType[0] | currentType;

		if(!re_child2Type.isEmpty() && re_child2Type.indexOf(currentTag)!=-1)//������ ��� ���� � �������� �������� child2-type
			t_variant.childiType[1] = t_variant.childiType[1] | currentType;

		if(!re_child3Type.isEmpty() && re_child3Type.indexOf(currentTag)!=-1)//������ ��� ���� � �������� �������� child3-type
			t_variant.childiType[2] = t_variant.childiType[2] | currentType;

		if(!re_childType.isEmpty() && re_childType.indexOf(currentTag)!=-1)//������ ��� ���� � �������� �������� child-type
			t_variant.childType = t_variant.childType | currentType;

		++i;
	} //������� ������ ��� ����� ������������

	return t_variant;
}

/*!
 * ������ ������ �������� �� xml �����
 * \param[in] filename ��� ����� ����������� ������ ��������
 * \return ��������� �������� (������ ���������� �����������!)
 * \throw char* ������ � �������
 */
patternContainer * readPatterns(QString &filename) throw (QString)
{
	patternContainer * data = new patternContainer();
	const QMap<QString,nodeType> & tags = buildTagsMap();
	QDomElement currentElement;

	QFile file(filename);					//��������� ���� � ���������
	if (!file.open(QIODevice::ReadOnly))	//��������
		throw QString("pattern-file open errror");			//������� ��� ������

	QDomDocument domDocument;				//��� ������� xml
	QString errorStr;						//����� ������ xml
	int errorLine,errorColumn;

	if (!domDocument.setContent(&file, false, &errorStr, &errorLine, &errorColumn)) //������������� ��������
	{
		throw  QString("pattern-xml parse error at line %1, column %2:\n%3").arg(errorLine).arg(errorColumn).arg(errorStr);//����������� ������
	}

	QDomElement rootElement = domDocument.documentElement();
	QDomNode n = rootElement.firstChild();	//n - ������� �� �������
	while (!n.isNull()) 
	{
		if (n.isElement()) 
		{
			currentElement = n.toElement();
			if( currentElement.tagName()==QString("default") && currentElement.hasAttribute("type") && tags.contains(currentElement.attribute("type")) )//���� ������ �����������
				data->addDefault(currentElement.attribute("type"), currentElement.text());
			if( currentElement.tagName()==QString("variant") && currentElement.hasAttribute("type") )//���� ������ ��������������
			{
				data->addVariant(QDomElementToVariant(currentElement));
			}
			
		}
		n = n.nextSibling();	//�������� �������
	}
	return data;
}

/*!
 *\brief ���������� ���� �� ������ ����������� xml ����
 *�� ������ xml ������ ��������� ��������������� ������ ����������� ���������.  � ����������� �� ���� ������� ���� ������������� ���� � ��������  xmlnode ������������ ����. �������� ���� ���� ��� �������� �������� �����. 
 *\param[in] xmlnode ���� xml ������, ��� �������� ����������� ��������������
 *\return ��������� �� ��������� ����
 */
node * readNode(const QDomElement & xmlnode)
{
	QString tag=xmlnode.tagName();
	node * result=NULL;
	QString errText = "Attribute %1 is missing from the tag %2 (line: %3; column: %4)";
	if(tag==QString("kmn"))
	{
		if(!xmlnode.hasAttribute("m"))	throw errText.arg("m").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		if(!xmlnode.hasAttribute("n"))	throw errText.arg("n").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_mn(xmlnode.attribute("m"),xmlnode.attribute("n"));
	}
	else if(tag==QString("km"))
	{
		if(!xmlnode.hasAttribute("m"))	throw errText.arg("m").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_m(xmlnode.attribute("m"));
	}
	else if(tag==QString("kxn"))
	{
		if(!xmlnode.hasAttribute("n"))	throw errText.arg("n").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_0n(xmlnode.attribute("n"));
	}
	else if(tag==QString("kmx"))
	{
		if(!xmlnode.hasAttribute("m"))	throw errText.arg("m").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_m0(xmlnode.attribute("m"));
	}
	else if(tag==QString("ks"))
	{
		result = new node_quantifier_star();
	}
	else if(tag==QString("kp"))
	{
		result = new node_quantifier_plus();
	}
	else if(tag==QString("kq"))
	{
		result = new node_quantifier_question();
	}
	else if(tag==QString("kmnp"))
	{
		if(!xmlnode.hasAttribute("m"))	throw errText.arg("m").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		if(!xmlnode.hasAttribute("n"))	throw errText.arg("n").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_mn_plus(xmlnode.attribute("m"),xmlnode.attribute("n"));
	}
	else if(tag==QString("kmp"))
	{
		if(!xmlnode.hasAttribute("m"))	throw errText.arg("m").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_m_plus(xmlnode.attribute("m"));
	}
	else if(tag==QString("kxnp"))
	{
		if(!xmlnode.hasAttribute("n"))	throw errText.arg("n").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_0n_plus(xmlnode.attribute("n"));
	}
	else if(tag==QString("kmxp"))
	{
		if(!xmlnode.hasAttribute("m"))	throw errText.arg("m").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_m0_plus(xmlnode.attribute("m"));
	}
	else if(tag==QString("ksp"))
	{
		result = new node_quantifier_star_plus();
	}
	else if(tag==QString("kpp"))
	{
		result = new node_quantifier_plus_plus();
	}
	else if(tag==QString("kqp"))
	{
		result = new node_quantifier_question_plus();
	}
	else if(tag==QString("kmnq"))
	{
		if(!xmlnode.hasAttribute("m"))	throw errText.arg("m").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		if(!xmlnode.hasAttribute("n"))	throw errText.arg("n").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_mn_question(xmlnode.attribute("m"),xmlnode.attribute("n"));
	}
	else if(tag==QString("kmq"))
	{
		if(!xmlnode.hasAttribute("m"))	throw errText.arg("m").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_m_question(xmlnode.attribute("m"));
	}
	else if(tag==QString("kxnq"))
	{
		if(!xmlnode.hasAttribute("n"))	throw errText.arg("n").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_0n_question(xmlnode.attribute("n"));
	}
	else if(tag==QString("kmxq"))
	{
		if(!xmlnode.hasAttribute("m"))	throw errText.arg("m").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_quantifier_m0_question(xmlnode.attribute("m"));
	}
	else if(tag==QString("ksq"))
	{
		result = new node_quantifier_star_question();
	}
	else if(tag==QString("kpq"))
	{
		result = new node_quantifier_plus_question();
	}
	else if(tag==QString("kqq"))
	{
		result = new node_quantifier_question_question();
	}
	else if(tag==QString("con"))
	{
		result = new node_concatenation();
	}
	else if(tag==QString("or"))
	{
		result = new node_oor();
	}
	else if(tag==QString("g"))
	{
		result = new node_group();
	}
	else if(tag==QString("gq"))
	{
		result = new node_group_question();
	}
	else if(tag==QString("go"))
	{
		result = new node_group_once();
	}
	else if(tag==QString("cm"))
	{
		result = new node_condition_mask();
	}
	else if(tag==QString("cmy"))
	{
		result = new node_condition_mask_yes();
	}
	else if(tag==QString("cf"))
	{
		result = new node_condition_forward();
	}
	else if(tag==QString("cfn"))
	{
		result = new node_condition_forward_negative();
	}
	else if(tag==QString("cb"))
	{
		result = new node_condition_back();
	}
	else if(tag==QString("cbn"))
	{
		result = new node_condition_back_negative();
	}
	else if(tag==QString("mi"))
	{
		result = new node_modifier_i();
	}
	else if(tag==QString("ms"))
	{
		result = new node_modifier_s();
	}
	else if(tag==QString("mu"))
	{
		result = new node_modifier_u();
	}
	else if(tag==QString("mm"))
	{
		result = new node_modifier_m();
	}
	else if(tag==QString("ad"))
	{
		result = new node_assert_d();
	}
	else if(tag==QString("ac"))
	{
		result = new node_assert_cap();
	}
	else if(tag==QString("ab"))
	{
		result = new node_assert_b();
	}
	else if(tag==QString("abb"))
	{
		result = new node_assert_b_big();
	}
	else if(tag==QString("aab"))
	{
		result = new node_assert_a_big();
	}
	else if(tag==QString("azb"))
	{
		result = new node_assert_z_big();
	}
	else if(tag==QString("az"))
	{
		result = new node_assert_z();
	}
	else if(tag==QString("od"))
	{
		result = new node_operand_d();
	}
	else if(tag==QString("odb"))
	{
		result = new node_operand_d_big();
	}
	else if(tag==QString("os"))
	{
		result = new node_operand_s();
	}
	else if(tag==QString("osb"))
	{
		result = new node_operand_s_big();
	}
	else if(tag==QString("ow"))
	{
		result = new node_operand_w();
	}
	else if(tag==QString("owb"))
	{
		result = new node_operand_w_big();
	}
	else if(tag==QString("dot"))
	{
		result = new node_dot();
	}
	else if(tag==QString("sc"))
	{
		if(!xmlnode.hasAttribute("text"))	throw errText.arg("text").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_symbol_class(xmlnode.attribute("text"));
	}
	else if(tag==QString("scn"))
	{
		if(!xmlnode.hasAttribute("text"))	throw errText.arg("text").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_symbol_class_negative(xmlnode.attribute("text"));
	}
	else if(tag==QString("range"))
	{
		if(!xmlnode.hasAttribute("start"))	throw errText.arg("start").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		if(!xmlnode.hasAttribute("end"))	throw errText.arg("end").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_range(xmlnode.attribute("start"),xmlnode.attribute("end"));
	}
	else if(tag==QString("symbol"))
	{
		if(!xmlnode.hasAttribute("text"))	throw errText.arg("text").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_symbol(xmlnode.attribute("text"));
	}
	else if(tag==QString("link"))
	{
		if(!xmlnode.hasAttribute("n"))	throw errText.arg("n").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_link(xmlnode.attribute("n"));
	}
	else if(tag==QString("oa"))
	{
		result = new node_operand_a();
	}
	else if(tag==QString("oe"))
	{
		result = new node_operand_e();
	}
	else if(tag==QString("on"))
	{
		result = new node_operand_n();
	}
	else if(tag==QString("ot"))
	{
		result = new node_operand_t();
	}
	else if(tag==QString("o8"))
	{
		if(!xmlnode.hasAttribute("n"))	throw errText.arg("n").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_operand_8(xmlnode.attribute("n"));
	}
	else if(tag==QString("o16"))
	{
		if(!xmlnode.hasAttribute("n"))	throw errText.arg("n").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_operand_16(xmlnode.attribute("n"));
	}
	else if(tag==QString("empty"))
	{
		result = new node_empty();
	}
	else if(tag==QString("t"))
	{
		if(!xmlnode.hasAttribute("text"))	throw errText.arg("text").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
		result = new node_otext(xmlnode.attribute("text"));
	}
	else
	{
		throw QString("unknown tag '%1' in line %2, column %3").arg(tag).arg(xmlnode.lineNumber()).arg(xmlnode.columnNumber());
	}

	QDomElement child = xmlnode.firstChildElement();
	while(!child.isNull())
	{
		result->addChild(readNode(child));
		child.nextSiblingElement();
	}
	return result;
}

/*!
 *\brief ��������� ������ �� �����
 *������ XML ���� � ���� DOM � ��������� ��������������� ������ � ������. ���������� NULL � ������ ������ � ������� �������������� �� �������. 
 *\param[in] filename  ��� �����
 *\return ������ �� ������� ���� ������
 */
node* readTree (QString &filename)
{
	static node_oor abc;
	return &abc;

	QFile file(filename);					//��������� ���� � ���������
	if (!file.open(QIODevice::ReadOnly))	//��������
		throw QString("tree-file open errror");			//������� ��� ������
	QDomDocument domDocument;				//��� ������� xml
	QString errorStr;						//����� ������ xml
	int errorLine,errorColumn;

	if (!domDocument.setContent(&file, false, &errorStr, &errorLine, &errorColumn)) //������������� ��������
	{
		throw  QString("tree-xml parse error at line %1, column %2:\n%3").arg(errorLine).arg(errorColumn).arg(errorStr);//����������� ������
	}

	QDomElement rootElement = domDocument.documentElement();
	QDomElement n = rootElement.firstChildElement();	//n - ������� �� �������
	if(n.isNull())
		throw QString("empty tree");
	return readNode(n);
}

/*!
 *\brief ��������� ������ �� ������� ������ ������ ����������
 * ������� ������� �������, �������, ������ ������� ����� ������ ������� ��������.
 *\param[in,out] str �������������� ������
 */
void postprocessing(QString * str)
{

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	
	//��������� ����� � �������
    QTextCodec *tc=QTextCodec::codecForName("windows-1251");
	QTextCodec *tcl=QTextCodec::codecForName("IBM 866");
	QTextCodec::setCodecForCStrings(tc);
	QTextCodec::setCodecForLocale(tcl);
	//setlocale( LC_ALL, "Russian_Russia.1251" );
	const char * sada;
	try
	{
		//������ ������
		tests t1;
		QTest::qExec(&t1);
		puts( qPrintable(QString("������� �����")));
		qDebug("%s",qPrintable(QString("������� �����")));
		//qDebug("%s",dfsdf);
	}
	catch(QString s)
	{
		qDebug("EXEPTION: %s!",qPrintable(s)); 
	}

    return a.exec();
}
