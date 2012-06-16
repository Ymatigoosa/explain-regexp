#include "tests.h"

Q_DECLARE_METATYPE(node *)

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

	 QTest::newRow("standart forms") << tree_standart_patterns() << QString("a или b");
	 QTest::newRow("alt with forms") << tree_alt_form() << QString("любое количество или отсутствие пробельных символов");
	 QTest::newRow("quantifier1") << tree_quantifier() << QString("любой символ 2 раза или любой символ 112 раз");
	 QTest::newRow("quantifier2") << tree_quantifier() << QString("любой символ 5 раз или любой символ 1024 раза");
	 QTest::newRow("alt pattern1") << tree_alt_pattern1() << QString("любая последовательность символов или её отсутсвие");
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
	QTest::addColumn<node*>("root");
	QTest::addColumn<QString>("expected");
	
	node * parent = tree_alt_pattern2();
	QTest::newRow("default1") << parent << QString("$1 или $2");
	parent = parent->child(1);
	QTest::newRow("variant1") << parent << QString("$1, или $2");
	parent = tree_alt_pattern3();
	QTest::newRow("variant2") << parent << QString("$1, или $2");
	parent = parent->child(0);
	QTest::newRow("default2") << parent << QString("$1 или $2");
	parent = tree_quantifier();
	QTest::newRow("quantifier1") << parent->child(0) << QString("$1 $m раза");
	QTest::newRow("quantifier2") << parent->child(1) << QString("$1 $m раз");
}
void tests::patternTest()
{
	QFETCH(node*,root);
    QFETCH(QString,expected);

	nodePattern * current_patterns =  patterns->getPatternFromType(root->type());
	QString result = root->pattern(*current_patterns);
	//delete root;
	printf("\nExpected: %s\n",qPrintable(QString(expected)));
	printf("Returned: %s\n",qPrintable(QString(result)));
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