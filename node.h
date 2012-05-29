#ifndef NODE_H
#define NODE_H
#include <QtCore>
#include "nodeType.h"
#include "nodepattern.h"
#include "variant.h"
#include "patterncontainer.h"

class node
{
private:
    QVector<node *> childs;
public:
    node();
    virtual QString tagName()=0 ;
    virtual nodeType type()=0;
    virtual bool hasArg(QString & arg) = 0;

    QString description(const patternContainer & patterns, int * num, node * parent=0, QString form = QString());
    QString pattern(const nodePattern & _nodePattern, node * parent=0, QString form = QString());
    bool check(const variant & pattern, node * parent = 0);
};

#endif // NODE_H
