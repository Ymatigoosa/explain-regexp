#ifndef TEST_DESCRIPTION_H
#define TEST_DESCRIPTION_H

#include <QObject>
#include <QtTest/QtTest>
#include "node.h"
#include "node_childs.h"

/*!
 * \brief Тесты node::description()
 * Класс на основе QtTest, осуществляет автоматический запуск тестов. Тестируемая функция node::description()
 */
class test_description : public QObject
{
    Q_OBJECT
private:
	node * tree_standart_patterns();
	node * tree_alt_pattern1();
	node * tree_quantifier();
private slots:
    void descriptionTest_data();
	void descriptionTest();
};

#endif // TEST_DESCRIPTION_H
