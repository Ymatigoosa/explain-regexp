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
}


int node::addChild(node * child)
{
	childs.append(child);
	return childs.count();
}


node * node::child(int n)
{
	return (n>=childs.size()) ? NULL : childs.at(n);
}

QString node::description(const patternContainer & patterns, int num, node * parent, QString form)
{
	QString current_pattern = this->pattern(patterns.getPatternFromType(this->type()),parent,form);
	QRegExp findDollar("\\$(1|2|3|m|n|text|start|end|X)(\\w*)");//регулярные выражения для поиска мест подставления шаблонов ( вроде $1g )
	QString _captured_type,_captured_form;//подстроки захваченные регулярным выражением
	QString insert;//строка которую вставляем
	static int new_num;	//номер для подстановки в следующий узел
	static int mask_count=1;//счетчик масок
	if(parent==NULL)
		mask_count=1;//первый заход в функцию, сбрасываем счетчик
	new_num=(num<0) ? (num-1) : (num+1);//если номер отрицателен, ведем подсчет но в отрицательных значениях
	int pos = findDollar.indexIn(current_pattern);//позиция найденной подстроки
	while(pos > -1)//пока есть такие конструкции
	{
		_captured_type = findDollar.cap(1);
		_captured_form = findDollar.cap(2);
		current_pattern.replace(pos,findDollar.matchedLength(),QString("%1"));//заменяем на внутренний формат подстановки qt

		//какой тип шаблона требуется
		if		(_captured_type=="1")		
		{
			if(this->child(0)==NULL)
				throw QString("node <%1> has too few childrens, need 1 (node number: %2)").arg(this->tagName()).arg( num<0 ? ~new_num : new_num);
			insert = this->child(0)->description(patterns,new_num, this, _captured_form);
		}
		else if	(_captured_type=="2")		
		{
			if(this->child(1)==NULL)
				throw QString("node <%1> has too few childrens, need 2 (node number: %2)").arg(this->tagName()).arg( num<0 ? ~new_num : new_num);
			insert = this->child(1)->description(patterns,new_num, this, _captured_form);
		}
		else if	(_captured_type=="3")		
		{
			if(this->child(2)==NULL)
				throw QString("node <%1> has too few childrens, need 3 (node number: %2)").arg(this->tagName()).arg( num<0 ? ~new_num : new_num);
			insert = this->child(2)->description(patterns,new_num, this, _captured_form);
		}
		else if	(_captured_type=="m")		
		{
			if(!this->hasArg("m"))
				throw QString("node <%1> has no 'm' argument (node number: %2)").arg(this->tagName()).arg( num<0 ? ~new_num : new_num);
			insert = this->m;
		}
		else if	(_captured_type=="n")		
		{
			if(!this->hasArg("n"))
				throw QString("node <%1> has no 'n' argument (node number: %2)").arg(this->tagName()).arg( num<0 ? ~new_num : new_num);
			insert = this->n;
		}
		else if	(_captured_type=="text")	
		{
			if(!this->hasArg("text"))
				throw QString("node <%1> has no 'text' argument (node number: %2)").arg(this->tagName()).arg( num<0 ? ~new_num : new_num);
			insert = this->text;
		}
		else if	(_captured_type=="start")	
		{
			if(!this->hasArg("start"))
				throw QString("node <%1> has no 'start' argument (node number: %2)").arg(this->tagName()).arg( num<0 ? ~new_num : new_num);
			insert = this->m;//атрибут start хранится в поле m
		}
		else if	(_captured_type=="end")		
		{
			if(!this->hasArg("end"))
				throw QString("node <%1> has no 'end' argument (node number: %2)").arg(this->tagName()).arg( num<0 ? ~new_num : new_num);
			insert = this->n;//атрибут end хранится в поле n
		}
		else if	(_captured_type=="X")		
		{
			insert = QString::number(mask_count++);//счетчик масок
		}

		current_pattern = current_pattern.arg(insert);

		pos = findDollar.indexIn(current_pattern);//следущая итерация
	}
	//номер узла
	if(num>=0)
		current_pattern = QString("<%1>%2</%1>").arg(num).arg(current_pattern);

	return current_pattern;
}

QString node::pattern(const nodePattern & _nodePattern, node * parent, QString form)
{
	for(int i=0;i<_nodePattern.variantPatterns.size();++i)
		if(this->check(_nodePattern.variantPatterns[i],parent,form))
			return _nodePattern.variantPatterns[i].pattern;
	return _nodePattern.defaultPattern;
}

bool node::check(const variant & pattern, node * parent,QString form)
{
	bool has_parent = parent !=NULL;
	bool has_child0 = this->child(0)!=NULL;
	bool has_child1 = this->child(1)!=NULL;
	bool has_child2 = this->child(2)!=NULL;

	bool flag_type = (pattern.type & this->type());
	bool flag_parentType = pattern.parentType==0 || (has_parent && pattern.parentType & parent->type());
	bool flag_child0Type = pattern.childiType[0]==0 || (has_child0 && pattern.childiType[0] & this->child(0)->type());
	bool flag_child1Type = pattern.childiType[1]==0 || (has_child1 && pattern.childiType[1] & this->child(1)->type());
	bool flag_child2Type = pattern.childiType[2]==0 || (has_child2 && pattern.childiType[2] & this->child(2)->type());
	bool flag_childType = pattern.childType==0 || 
		(has_child0 && pattern.childType & this->child(0)->type()) ||
		(has_child1 && pattern.childType & this->child(1)->type()) ||
		(has_child2 && pattern.childType & this->child(2)->type());
	bool flag_content = pattern.content.isNull() || (this->hasArg("text") && QRegExp(QString(pattern.content)).exactMatch(this->text));
	bool flag_parentContent = pattern.parentContent.isNull() || (has_parent && parent->hasArg("text") && QRegExp(QString(pattern.parentContent)).exactMatch(parent->text));
	bool flag_child0Content = pattern.childiContent[0].isNull() || (has_child0 && this->child(0)->hasArg("text") && QRegExp(QString(pattern.childiContent[0])).exactMatch(this->child(0)->text));
	bool flag_child1Content = pattern.childiContent[1].isNull() || (has_child1 && this->child(1)->hasArg("text") && QRegExp(QString(pattern.childiContent[1])).exactMatch(this->child(1)->text));
	bool flag_child2Content = pattern.childiContent[2].isNull() || (has_child2 && this->child(2)->hasArg("text") && QRegExp(QString(pattern.childiContent[2])).exactMatch(this->child(2)->text));
	bool flag_form = form == pattern.form;
	bool flag_m = QRegExp(QString(pattern.m)).exactMatch(this->m);
	bool flag_n = QRegExp(QString(pattern.n)).exactMatch(this->n);

	return flag_type && flag_parentType && flag_child0Type && flag_child1Type && flag_child2Type && flag_childType && flag_content && flag_parentContent && flag_child0Content && flag_child1Content && flag_child2Content && flag_form && flag_m && flag_n;
}