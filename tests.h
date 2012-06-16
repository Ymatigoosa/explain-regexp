#ifndef tests_H
#define tests_H

#include <QObject>
#include <QtTest/QtTest>
#include "node.h"
#include "node_childs.h"

/*!
 * \brief ����� node::description()
 * ����� �� ������ QtTest, ������������ �������������� ������ ������. ����������� ������� node::description()
 */
class tests : public QObject
{
    Q_OBJECT
private:
	node * tree_standart_patterns();
	node * tree_alt_pattern1();
	node * tree_alt_form();
	node * tree_quantifier();
	node * tree_quantifier2();
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
