#ifndef TEST_DESCRIPTION_H
#define TEST_DESCRIPTION_H

#include <QObject>
#include <QtTest/QtTest>
#include "node.h"
#include "node_childs.h"

/*!
 * \brief ����� node::description()
 * ����� �� ������ QtTest, ������������ �������������� ������ ������. ����������� ������� node::description()
 */
class test_description : public QObject
{
    Q_OBJECT
private:
	node * tree_standart_patterns();
	node * tree_alt_pattern1();
	node * tree_quantifier();
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

#endif // TEST_DESCRIPTION_H
