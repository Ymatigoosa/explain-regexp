#include "test_description.h"


Q_DECLARE_METATYPE(node *)

node * test_description::tree_standart_patterns()
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

node * test_description::tree_alt_pattern1()
{
	node * parent = new node_quantifier_star();
	parent->addChild(new node_dot());

	return parent;
}

node * test_description::tree_quantifier()
{
	node * parent = new node_oor();
	parent->addChild(new node_quantifier_m("2"));
	parent->child(0)->addChild(new node_dot());

	parent->addChild(new node_quantifier_m("122"));
	parent->child(1)->addChild(new node_dot());

	return parent;
}

void test_description::descriptionTest_data()
{
	 QTest::addColumn<node *>("vertex of the tree");
	 QTest::addColumn<QString>("expected description");

	 QTest::newRow("standart patterns") << tree_standart_patterns() << QString("����� �� �������� �� 0 �� 9 �� ����� 1 ����� ��� ������ �� �������� �� A �� Z �� ����� 1 ����� ��� ������ �� �������� �� a �� z �� ����� 1 ����");
	 QTest::newRow("quantifier") << tree_quantifier() << QString("����� ������ 2 ����� ��� ������ ������ 112 ���");
	 QTest::newRow("alt pattern1") << tree_alt_pattern1() << QString("����� ������������������ �������� ��� � ���������");
}
void test_description::descriptionTest()
{
	QFETCH(node *, parent);
    QFETCH(QString, expected);
	
	/*QString result =  parent->description();*/
}