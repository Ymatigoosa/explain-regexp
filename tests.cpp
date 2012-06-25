#include "tests.h"

Q_DECLARE_METATYPE(node *)
Q_DECLARE_METATYPE(variant)

patternContainer * readPatterns(QString &filename) throw (...);

node * tests::tree_standart_patterns()
{
	node * parent = new node_oor();
	parent->addChild(new node_otext(QString("a")));
	parent->addChild(new node_otext(QString("b")));

	return parent;
}

node * tests::tree_alt_pattern1()
{
	node * parent = new node_quantifier_star();
	parent->addChild(new node_dot());

	return parent;
}
node * tests::tree_alt_pattern2()
{
	node * parent = new node_oor();

	parent->addChild(new node_oor());
	parent->child(0)->addChild(new node_quantifier_plus());
	parent->child(0)->child(0)->addChild(new node_symbol_class("A-Z"));

	parent->child(0)->addChild(new node_quantifier_plus());
	parent->child(0)->child(1)->addChild(new node_symbol_class("a-z"));

	parent->addChild(new node_quantifier_plus());
	parent->child(1)->addChild(new node_symbol_class("0-9"));

	return parent;
}
node * tests::tree_alt_pattern3()
{
	node * parent = new node_oor();

	parent->addChild(new node_oor());
	parent->child(0)->addChild(new node_otext(QString("a")));
	parent->child(0)->addChild(new node_otext(QString("b")));
	parent->addChild(new node_otext(QString("c")));

	return parent;
}
node * tests::tree_alt_pattern4()
{
	node * parent = new node_concatenation();
	parent->addChild(new node_link(QString("1")));
	parent->addChild(new node_link(QString("2")));

	return parent;
}
node * tests::tree_alt_form()
{
	node * parent = new node_quantifier_star();
	parent->addChild(new node_operand_s());

	return parent;
}

node * tests::tree_quantifier()
{
	node * parent = new node_oor();
	parent->addChild(new node_quantifier_m("2"));
	parent->child(0)->addChild(new node_dot());

	parent->addChild(new node_quantifier_m("112"));
	parent->child(1)->addChild(new node_dot());

	return parent;
}
node * tests::tree_quantifier2()
{
	node * parent = new node_oor();
	parent->addChild(new node_quantifier_m("5"));
	parent->child(0)->addChild(new node_dot());

	parent->addChild(new node_quantifier_m("1024"));
	parent->child(1)->addChild(new node_dot());

	return parent;
}

void tests::descriptionTest_data()
{
	 QTest::addColumn<node*>("root");
	 QTest::addColumn<QString>("expected");

	 QTest::newRow("alt pattern2") << tree_alt_pattern2() << QString("����� ���������� ����� �� �������� �� A �� Z ��� ����� ���������� ����� �� �������� �� a �� z, ��� ����� ���������� ����� �� �������� �� 0 �� 9");
	 QTest::newRow("standart patterns") << tree_standart_patterns() << QString("a ��� b");
	 QTest::newRow("alt with forms") << tree_alt_form() << QString("����� ���������� ��� ���������� ���������� ��������");
	 QTest::newRow("quantifier1") << tree_quantifier() << QString("����� ������ 2 ���� ��� ����� ������ 112 ���");
	 QTest::newRow("quantifier2") << tree_quantifier2() << QString("����� ������ 5 ��� ��� ����� ������ 1024 ����");
	 QTest::newRow("alt pattern1") << tree_alt_pattern1() << QString("����� ������������������ �������� ��� � ����������");

	
}

void tests::descriptionTest()
{
	QFETCH(node*,root);
    QFETCH(QString,expected);
	
	QString result =  root->description(*patterns);
	delete root;
	if(result!=expected)
	{
		printf("\nExpected: %s\n",qPrintable(QString(expected)));
		printf("Returned: %s\n",qPrintable(QString(result)));	
		QFAIL("result != expected");
	}
}

void tests::patternTest_data()
{
	QTest::addColumn<node*>("parent");
	QTest::addColumn<node*>("current");
	QTest::addColumn<QString>("form");
	QTest::addColumn<QString>("expected");
	
	node *parent, *current; //��������� ���������� ��� ���������� �������

	parent = tree_alt_form();
	current = parent->child(0);
	QTest::newRow("form") << parent << current << QString("g") << QString("���������� ��������");

	parent = 0;
	current = tree_alt_pattern3();
	QTest::newRow("variant") << parent << current << QString() << QString("$1, ��� $2");

	parent = tree_alt_pattern3();
	current = parent->child(0);
	QTest::newRow("default") << parent << current << QString() << QString("$1 ��� $2");

	parent = tree_alt_pattern4();
	current = parent->child(0);
	QTest::newRow("default&parent") << parent << current << QString() << QString("������ �� �������� $n");

	parent = tree_quantifier();
	current =  parent->child(0);
	QTest::newRow("quantifier1") << parent << current << QString() << QString("$1 $m ����");

	parent = tree_quantifier();
	current =  parent->child(1);
	QTest::newRow("quantifier2") << parent << current << QString() << QString("$1 $m ���");

	parent = tree_quantifier2();
	current =  parent->child(0);
	QTest::newRow("quantifier3") << parent << current << QString() << QString("$1 $m ���");

	parent = tree_quantifier2();
	current =  parent->child(1);
	QTest::newRow("quantifier4") << parent << current << QString() << QString("$1 $m ����");
}
void tests::patternTest()
{
	QFETCH(node*,parent);
	QFETCH(node*,current);
	QFETCH(QString,form);
    QFETCH(QString,expected);

	nodePattern current_patterns =  patterns->getPatternFromType(current->type());
	QString result = current->pattern(current_patterns,parent,form);
	if(parent==0)
		delete current;
	else
		delete parent;
	if(result!=expected)
	{
		printf("\nExpected: %s\n",qPrintable(QString(expected)));
		printf("Returned: %s\n",qPrintable(QString(result)));	
		QFAIL("result != expected");
	}
}

void tests::checkTest_data()
{
	QTest::addColumn<node*>("parent");
	QTest::addColumn<node*>("current");
	QTest::addColumn<variant>("pattern");
	QTest::addColumn<QString>("form");
	QTest::addColumn<bool>("expected");
	
	node *parent, *current;//��������� ���������� ��� ���������� �������
	variant temp;

	temp.form = "g";
	temp.type = temp.type | operand_s;
	parent = tree_alt_form();
	current = parent->child(0);
	QTest::newRow("form accept") << parent << current << temp << QString("g") << true;

	temp=variant();
	temp.form = "g";
	temp.type = temp.type | oor;
	parent = tree_alt_pattern2();
	current = parent->child(0);
	QTest::newRow("form dont accept") << parent << current << temp << QString() << false;

	temp=variant();
	temp.type = temp.type | oor;
	temp.childiType[0] = oor;
	parent = 0;
	current = tree_alt_pattern3();
	QTest::newRow("variant accept") << parent << current << temp << QString() << true;

	temp=variant();
	temp.type = temp.type | oor;
	temp.childiType[1] = oor;
	parent = 0;
	current = tree_alt_pattern2();
	QTest::newRow("variant dont accept") << parent << current << temp << QString() << false;
}	

void tests::checkTest()
{
	QFETCH(node*,parent);
	QFETCH(node*,current);
	QFETCH(variant,pattern);
	QFETCH(QString,form);
    QFETCH(bool,expected);

	bool result = current->check(pattern,parent,form);
	if(parent==0)
		delete current;
	else
		delete parent;
	QVERIFY(result==expected);
}

void tests::hasArgTest_data()
{
	QTest::addColumn<node*>("parent");
	QTest::addColumn<QString>("arg");
	QTest::addColumn<bool>("expected");
	//��������� ���������� ��� ���������� �������
	node *parent;

	parent = new node_quantifier_mn("5","16");
	QTest::newRow("right arg") << parent << QString("m") << true;

	parent = new node_quantifier_m("5");
	QTest::newRow("wrong arg") << parent << QString("n") << false;

	parent = new node_oor();
	QTest::newRow("without args") << parent << QString("n") << false;

	parent = new node_otext(QString("saddas"));
	QTest::newRow("right arg2") << parent << QString("text") << true;
}
	
void tests::hasArgTest()
{
	QFETCH(node*,parent);
	QFETCH(QString,arg);
	QFETCH(bool,expected);

	bool result = parent->hasArg(arg);
	delete parent;
	QVERIFY(result==expected);
}

void tests::postprocessingTest_data()
{
	QTest::addColumn<QString>("str");
	QTest::addColumn<QString>("expected");

	QTest::newRow("comma") << QString("a,, ��� b") << QString("a, ��� b") ;
	QTest::newRow("brackets") << QString("(a ��� (b))") << QString("(a ��� (b) )") ;
	QTest::newRow("space") << QString(" a    ��� b   ") << QString("a ��� b") ;
	QTest::newRow("all") << QString(" (a    ���,, (b)   )") << QString("(a ���, (b) )") ;
}
	
void tests::postprocessingTest()
{
	QFETCH(QString,str);
	QFETCH(QString,expected);
	
	postprocessing(str);
	if(str!=expected)
	{
		printf("\nExpected: %s\n",qPrintable(QString(expected)));
		printf("str: %s\n",qPrintable(QString(str)));	
		QFAIL("str != expected");
	}
}

void tests::initTestCase()
{
	patterns = readPatterns(QString("patterns.xml"));
}

void tests::cleanupTestCase()
{
	delete patterns;
}