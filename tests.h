#ifndef tests_H
#define tests_H

#include <QObject>
#include <QtTest/QtTest>
#include "node.h"
#include "node_childs.h"

/*!
 * \brief ����� 
 * ����� �� ������ QtTest, ������������ �������������� ������ ������. ����������� ������� node::description(), node::pattern(), node::hasArg(), node::check()
 */
class tests : public QObject
{
    Q_OBJECT
public:
	/*!
	 ������� ������ ����:
	 \dot
	 digraph g{
	 sc1 [label="[...]"]
	 sc2 [label="[...]"]
	 sc3 [label="[...]"]
	 or1 [label="|"]
	 or2 [label="|"]
	 q1  [label="+"]
	 q2  [label="+"]
	 q3  [label="+"]
	 or1 -> q1
	 q1 -> sc1
	 sc1 -> "0-9"
	 or1 -> or2
	 or2 -> q2
	 q2 -> sc2
	 sc2 -> "A-Z"
	 or2 -> q3
	 q3 -> sc3
	 sc3 -> "a-z"
	 }
	 \enddot
	 */
	node * tree_standart_patterns();
	
	/*!
	 ������� ������ ����:
	 \dot
	 digraph g{
	 "*"->"."
	 }
	 \enddot
	 */
	node * tree_alt_pattern1();

	/*!
	 ������� ������ ����:
	 \dot
	 digraph g{
	 "*"->"\s"
	 }
	 \enddot
	 */
	node * tree_alt_form();

	/*!
	 ������� ������ ����:
	 \dot
	 digraph g{
	 "|"->"{2}"
	 "|"->"{122}"
	 }
	 \enddot
	 */
	node * tree_quantifier();

	/*!
	 ������� ������ ����:
	 \dot
	 digraph g{
	 "|"->"{5}"
	 "|"->"{1024}"
	 }
	 \enddot
	 */
	node * tree_quantifier2();
private:
	patternContainer * patterns;
private slots:
	
	/*!
	 * ����� ������� ������ ������� �� �����
	 */
	void initTestCase();
	
	/*!
	 * ����� ������ ������� ������
	 */
	void cleanupTestCase();

	/*!
	 * ������ ��� ������ (�������/������ ��������)
	 */
    void descriptionTest_data();
	
	/*!
	 * ������ ���������� �����
	 */
	void descriptionTest();
};

#endif // tests_H
