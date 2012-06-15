#include "node.h"

node::node()
{
}

node::~node()
{
	int count = childs.count();
	for(int i=0;i<count;++i)
	{
		delete childs[i];
	}
	delete this;
}


int node::addChild(node * child)
{
	childs.append(child);
	return childs.count();
}


node * node::child(int n)
{
	return childs.at(n);
}