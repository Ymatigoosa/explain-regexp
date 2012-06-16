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
	parent->addChild(new node_quantifier_plus());
	parent->child(0)->addChild(new node_symbol_class());
	parent->child(0)->child(0)->addChild(new node_range("0","9"));

	parent->addChild(new node_oor());
	parent->child(1)->addChild(new node_quantifier_plus());
	parent->child(1)->child(0)->addChild(new node_symbol_class());
	parent->child(1)->child(0)->child(0)->addChild(new node_range("A","Z"));

	parent->child(1)->addChild(new node_quantifier_plus());
	parent->child(1)->child(1)->addChild(new node_symbol_class());
	parent->child(1)->child(1)->child(0)->addChild(new node_range("a","z"));

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

	parent->addChild(new node_quantifier_m("122"));
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

	 QTest::newRow("standart patterns") << tree_standart_patterns() << QString("a или b");
	 QTest::newRow("alt with forms") << tree_alt_form() << QString("любое количество или отсутствие пробельных символов");
	 QTest::newRow("quantifier1") << tree_quantifier() << QString("любой символ 2 раза или любой символ 112 раз");
	 QTest::newRow("quantifier2") << tree_quantifier() << QString("любой символ 5 раз или любой символ 1024 раза");
	 QTest::newRow("alt pattern1") << tree_alt_pattern1() << QString("любая последовательность символов или её отсутствие");
	 QTest::newRow("alt pattern2") << tree_alt_pattern2() << QString("любой из символов от 0 до 9 не менее 1 раза или любой из символов от A до Z не менее 1 раза, или любой из символов от a до z не менее 1 раза");

	
}

void tests::descriptionTest()
{
	QFETCH(node*,root);
    QFETCH(QString,expected);
	
	QString result =  root->description(*patterns);
	delete root;
	printf("\nExpected: %s\n",qPrintable(QString(expected)));
	printf("Returned: %s\n",qPrintable(QString(result)));	
	QVERIFY(result==expected);	
}

void tests::patternTest_data()
{
	QTest::addColumn<node*>("parent");
	QTest::addColumn<node*>("current");
	QTest::addColumn<QString>("expected");
	
	node *parent, *current;
	parent = 0;
	current = tree_alt_pattern2();
	QTest::newRow("default1") << parent << current << QString("$1 или $2");

	parent = tree_alt_pattern2();
	current = parent->child(1);
	QTest::newRow("variant1") << parent << current << QString("$1, или $2");

	parent = 0;
	current = tree_alt_pattern3();
	QTest::newRow("variant2") << parent << current << QString("$1, или $2");

	parent = tree_alt_pattern3();
	current = parent->child(0);
	QTest::newRow("default2") << parent << current << QString("$1 или $2");

	parent = tree_quantifier();
	current =  parent->child(0);
	QTest::newRow("quantifier1") << parent << current << QString("$1 $m раза");

	parent = tree_quantifier();
	current =  parent->child(1);
	QTest::newRow("quantifier2") << parent << current << QString("$1 $m раз");
}
void tests::patternTest()
{
	QFETCH(node*,parent);
	QFETCH(node*,current);
    QFETCH(QString,expected);

	nodePattern * current_patterns =  patterns->getPatternFromType(current->type());
	QString result = current->pattern(*current_patterns);
	if(parent==0)
		delete current;
	else
		delete parent;
	printf("\nExpected: %s\n",qPrintable(QString(expected)));
	printf("Returned: %s\n",qPrintable(QString(result)));
	QVERIFY(result==expected);
}

void tests::checkTest_data()
{
	QTest::addColumn<node*>("parent");
	QTest::addColumn<node*>("current");
	QTest::addColumn<variant>("pattern");
	QTest::addColumn<bool>("expected");
	
	node *parent, *current;//временные переменные для заполнения таблицы
	variant temp;

	temp.form = "g";
	parent = tree_alt_form();
	current = parent->child(0);
	QTest::newRow("form accept") << parent << current << temp << true;

	temp.form = "g";
	parent = tree_alt_pattern1();
	current = parent->child(0);
	QTest::newRow("form dont accept") << parent << current << temp << false;

	temp.childiType[0] = oor;
	parent = 0;
	current = tree_alt_pattern3();
	QTest::newRow("variant accept") << parent << current << temp << true;

	temp.childiType[0] = oor;
	parent = 0;
	current = tree_alt_pattern2();
	QTest::newRow("variant dont accept") << parent << current << temp << false;
}	

void tests::checkTest()
{
	QFETCH(node*,parent);
	QFETCH(node*,current);
	QFETCH(variant,pattern);
    QFETCH(bool,expected);

	bool result = current->check(pattern,parent);
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
	//временные переменные для заполнения таблицы
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

void tests::initTestCase()
{
	patterns = readPatterns(QString("patterns.xml"));
}

void tests::cleanupTestCase()
{
	delete patterns;
}