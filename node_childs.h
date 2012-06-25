/*!
 * \file node_childs.h
 * Содержит описание классив наследников node
 */
#pragma once
#include "node.h"
#include "nodeType.h"
#pragma warning( disable : 4100 )

/*!
 * \brief Узел: {m,n}
 * Класс для определения узла типа {m,n}
 */
class node_quantifier_mn :	public node
{
public:
	//QString m;
	//QString n;

	node_quantifier_mn(QString _m,QString _n)
	{ m=_m;n=_n;	}

	QString tagName()///<название тега
	{	return QString("kmn");	}

	nodeType type()///<тип 
	{	return quantifier_mn;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m}
 * Класс для определения узла типа {m}
 */
class node_quantifier_m :	public node
{
public:
	//QString m;

	node_quantifier_m(QString _m)
	{ m=_m;	}

	QString tagName()///<название тега
	{	return QString("km");	}
	nodeType type()///<тип 
	{	return quantifier_m;	}
	bool hasArg(QString arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: {,n}
 * Класс для определения узла типа {,n}
 */
class node_quantifier_0n :	public node
{
public:
	//QString n;


	node_quantifier_0n(QString _n)///<конструктор по умолчанию
	{	n=_n;}

	QString tagName()///<название тега
	{	return QString("kxn");	}

	nodeType type()///<тип 
	{	return quantifier_0n;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m,}
 * Класс для определения узла типа {m,}
 */
class node_quantifier_m0 :	public node
{
public:
	//QString m;

	node_quantifier_m0(QString _m)
	{	m=_m;}

	QString tagName()///<название тега
	{	return QString("kmx");	}

	nodeType type()///<тип 
	{	return quantifier_m0;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: *
 * Класс для определения узла типа *
 */
class node_quantifier_star :	public node
{
public:
	node_quantifier_star()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ks");	}

	nodeType type()///<тип 
	{	return quantifier_star;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: +
 * Класс для определения узла типа +
 */
class node_quantifier_plus :	public node
{
public:
	node_quantifier_plus()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kp");	}

	nodeType type()///<тип 
	{	return quantifier_plus;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: ?
 * Класс для определения узла типа ?
 */
class node_quantifier_question :	public node
{
public:
	node_quantifier_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kq");	}

	nodeType type()///<тип 
	{	return quantifier_question;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: {m,n}+
 * Класс для определения узла типа {m,n}+
 */
class node_quantifier_mn_plus :	public node
{
public:
	//QString n;
	//QString m;

	node_quantifier_mn_plus(QString _m,QString _n)
	{	m=_m;n=_n;}

	QString tagName()///<название тега
	{	return QString("kmnp");	}

	nodeType type()///<тип 
	{	return quantifier_mn_plus;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m}+
 * Класс для определения узла типа {m}+
 */
class node_quantifier_m_plus :	public node
{
public:
	//QString m;

	node_quantifier_m_plus(QString _m)
	{	m=_m;}

	QString tagName()///<название тега
	{	return QString("kmp");	}

	nodeType type()///<тип 
	{	return quantifier_m_plus;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: {,n}+
 * Класс для определения узла типа {,n}+
 */
class node_quantifier_0n_plus :	public node
{
public:
	//QString n;

	node_quantifier_0n_plus(QString _n)
	{	n=_n;}

	QString tagName()///<название тега
	{	return QString("kxnp");	}

	nodeType type()///<тип 
	{	return quantifier_0n_plus;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m,}+
 * Класс для определения узла типа {m,}+
 */
class node_quantifier_m0_plus :	public node
{
public:
	//QString m;

	node_quantifier_m0_plus(QString _m)
	{	m=_m;}

	QString tagName()///<название тега
	{	return QString("kmxp");	}

	nodeType type()///<тип 
	{	return quantifier_m0_plus;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: *+
 * Класс для определения узла типа *+
 */
class node_quantifier_star_plus :	public node
{
public:
	node_quantifier_star_plus()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ksp");	}

	nodeType type()///<тип 
	{	return quantifier_star_plus;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: ++
 * Класс для определения узла типа ++
 */
class node_quantifier_plus_plus :	public node
{
public:
	node_quantifier_plus_plus()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kpp");	}

	nodeType type()///<тип 
	{	return quantifier_plus_plus;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: ?+
 * Класс для определения узла типа ?+
 */
class node_quantifier_question_plus :	public node
{
public:
	node_quantifier_question_plus()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kqp");	}

	nodeType type()///<тип 
	{	return quantifier_question_plus;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: {m,n}?
 * Класс для определения узла типа {m,n}?
 */
class node_quantifier_mn_question :	public node
{
public:
	//QString n;
	//QString m;

	node_quantifier_mn_question(QString _m,QString _n)
	{	m=_m;n=_n;}

	QString tagName()///<название тега
	{	return QString("kmnq");	}

	nodeType type()///<тип 
	{	return quantifier_mn_question;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m}?
 * Класс для определения узла типа {m}?
 */
class node_quantifier_m_question :	public node
{
public:
	//QString m;

	node_quantifier_m_question(QString _m)
	{	m=_m;}

	QString tagName()///<название тега
	{	return QString("kmq");	}

	nodeType type()///<тип 
	{	return quantifier_m_question;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: {,n}?
 * Класс для определения узла типа {,n}?
 */
class node_quantifier_0n_question :	public node
{
public:
	//QString n;

	node_quantifier_0n_question(QString _n)
	{	n=_n;}

	QString tagName()///<название тега
	{	return QString("kxnq");	}

	nodeType type()///<тип 
	{	return quantifier_0n_question;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m,}?
 * Класс для определения узла типа {m,}?
 */
class node_quantifier_m0_question :	public node
{
public:
	//QString m;

	node_quantifier_m0_question(QString _m)///<конструктор по умолчанию
	{	m=_m;}

	QString tagName()///<название тега
	{	return QString("kmxq");	}

	nodeType type()///<тип 
	{	return quantifier_m0_question;	}

	bool hasArg(QString arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: *?
 * Класс для определения узла типа *?
 */
class node_quantifier_star_question :	public node
{
public:

	node_quantifier_star_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ksq");	}

	nodeType type()///<тип 
	{	return quantifier_star_question;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: +?
 * Класс для определения узла типа +?
 */
class node_quantifier_plus_question :	public node
{
public:

	node_quantifier_plus_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kpq");	}

	nodeType type()///<тип 
	{	return quantifier_plus_question;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: ??
 * Класс для определения узла типа ??
 */
class node_quantifier_question_question :	public node
{
public:

	node_quantifier_question_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kqq");	}

	nodeType type()///<тип 
	{	return quantifier_question_question;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: конкатенация
 * Класс для определения узла типа конкатенация
 */
class node_concatenation :	public node
{
public:

	node_concatenation()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("con");	}

	nodeType type()///<тип 
	{	return concatenation;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: |
 * Класс для определения узла типа |
 */
class node_oor :	public node
{
public:

	node_oor()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("or");	}

	nodeType type()///<тип 
	{	return oor;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: ( )
 * Класс для определения узла типа ( )
 */
class node_group :	public node
{
public:

	node_group()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("g");	}

	nodeType type()///<тип 
	{	return group;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?: )
 * Класс для определения узла типа (?: )
 */
class node_group_question :	public node
{
public:

	node_group_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("gq");	}

	nodeType type()///<тип 
	{	return group_question;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?> )
 * Класс для определения узла типа (?> )
 */
class node_group_once :	public node
{
public:

	node_group_once()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("go");	}

	nodeType type()///<тип 
	{	return group_once;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?(условие) подшаблон1| подшаблон2)
 * Класс для определения узла типа (?(условие) подшаблон1| подшаблон2)
 */
class node_condition_mask :	public node
{
public:

	node_condition_mask()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("cm");	}

	nodeType type()///<тип 
	{	return condition_mask;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?(условие) подшаблон1)
 * Класс для определения узла типа (?(условие) подшаблон1)
 */
class node_condition_mask_yes :	public node
{
public:

	node_condition_mask_yes()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("cmy");	}

	nodeType type()///<тип 
	{	return condition_mask_yes;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?=text)
 * Класс для определения узла типа (?=text)
 */
class node_condition_forward :	public node
{
public:

	node_condition_forward()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("cf");	}

	nodeType type()///<тип 
	{	return condition_forward;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?!text)
 * Класс для определения узла типа (?!text)
 */
class node_condition_forward_negative :	public node
{
public:

	node_condition_forward_negative()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("cfn");	}

	nodeType type()///<тип 
	{	return condition_forward_negative;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?<=text)
 * Класс для определения узла типа (?<=text)
 */
class node_condition_back :	public node
{
public:

	node_condition_back()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("cb");	}

	nodeType type()///<тип 
	{	return condition_back;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?<!text)
 * Класс для определения узла типа (?<!text)
 */
class node_condition_back_negative :	public node
{
public:

	node_condition_back_negative()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("cbn");	}

	nodeType type()///<тип 
	{	return condition_back_negative;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?i)
 * Класс для определения узла типа (?i)
 */
class node_modifier_i :	public node
{
public:

	node_modifier_i()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("mi");	}

	nodeType type()///<тип 
	{	return modifier_i;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?s)
 * Класс для определения узла типа (?s)
 */
class node_modifier_s :	public node
{
public:

	node_modifier_s()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ms");	}

	nodeType type()///<тип 
	{	return modifier_s;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?U)
 * Класс для определения узла типа (?U)
 */
class node_modifier_u :	public node
{
public:

	node_modifier_u()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("mu");	}

	nodeType type()///<тип 
	{	return modifier_u;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: (?m)
 * Класс для определения узла типа (?m)
 */
class node_modifier_m :	public node
{
public:

	node_modifier_m()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("mm");	}

	nodeType type()///<тип 
	{	return modifier_m;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: $
 * Класс для определения узла типа $
 */
class node_assert_d :	public node
{
public:

	node_assert_d()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ad");	}

	nodeType type()///<тип 
	{	return assert_d;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: ^
 * Класс для определения узла типа ^
 */
class node_assert_cap :	public node
{
public:

	node_assert_cap()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ac");	}

	nodeType type()///<тип 
	{	return assert_cap;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\b
 * Класс для определения узла типа \\b
 */
class node_assert_b :	public node
{
public:

	node_assert_b()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ab");	}

	nodeType type()///<тип 
	{	return assert_b;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\В
 * Класс для определения узла типа \\В
 */
class node_assert_b_big :	public node
{
public:

	node_assert_b_big()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("abb");	}

	nodeType type()///<тип 
	{	return assert_b_big;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\А
 * Класс для определения узла типа \\А
 */
class node_assert_a_big :	public node
{
public:

	node_assert_a_big()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("aab");	}

	nodeType type()///<тип 
	{	return assert_a_big;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\Z
 * Класс для определения узла типа \\Z
 */
class node_assert_z_big :	public node
{
public:

	node_assert_z_big()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("azb");	}

	nodeType type()///<тип 
	{	return assert_z_big;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\z
 * Класс для определения узла типа \\z
 */
class node_assert_z :	public node
{
public:

	node_assert_z()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("az");	}

	nodeType type()///<тип 
	{	return assert_z;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\d
 * Класс для определения узла типа \\d
 */
class node_operand_d :	public node
{
public:

	node_operand_d()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("od");	}

	nodeType type()///<тип 
	{	return operand_d;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\D
 * Класс для определения узла типа \\D
 */
class node_operand_d_big :	public node
{
public:

	node_operand_d_big()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("odb");	}

	nodeType type()///<тип 
	{	return operand_d_big;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\s
 * Класс для определения узла типа \\s
 */
class node_operand_s :	public node
{
public:

	node_operand_s()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("os");	}

	nodeType type()///<тип 
	{	return operand_s;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\S
 * Класс для определения узла типа \\S
 */
class node_operand_s_big :	public node
{
public:

	node_operand_s_big()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("osb");	}

	nodeType type()///<тип 
	{	return operand_s_big;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\w
 * Класс для определения узла типа \\w
 */
class node_operand_w :	public node
{
public:

	node_operand_w()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ow");	}

	nodeType type()///<тип 
	{	return operand_w;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\W
 * Класс для определения узла типа \\W
 */
class node_operand_w_big :	public node
{
public:

	node_operand_w_big()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("owb");	}

	nodeType type()///<тип 
	{	return operand_w_big;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: .
 * Класс для определения узла типа .
 */
class node_dot :	public node
{
public:

	node_dot()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("dot");	}

	nodeType type()///<тип 
	{	return dot;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: a-z(внутри [ ])
 * Класс для определения узла типа a-z(внутри [ ])
 */
class node_range :	public node
{
public:
	node_range(QString _start,QString _end)
	{ m=_start;	n=_end;	}

	QString tagName()///<название тега
	{	return QString("range");	}

	nodeType type()///<тип 
	{	return range;	}

	bool hasArg(QString arg)
	{	return (arg==QString("start") || arg==QString("end")) ? true : false;	}
};

/*!
 * \brief Узел: символ(внутри [ ])
 * Класс для определения узла типа символ(внутри [ ])
 */
class node_symbol :	public node
{
public:
	//QString text;

	node_symbol(QString _text)
	{	text=_text;}

	QString tagName()///<название тега
	{	return QString("symbol");	}

	nodeType type()///<тип 
	{	return symbol;	}

	bool hasArg(QString arg)
	{	return (arg==QString("text") ) ? true : false;	}
};

/*!
 * \brief Узел: [symb]
 * Класс для определения узла типа [symb]
 */
class node_symbol_class :	public node
{
public:

	node_symbol_class(QString text)
	{
		int _size = text.size();
		for(int i=0;i<_size;++i)
		{
			if(i+3<=_size && text[i+1]=='-')
			{
				this->addChild(new node_range(QString(text[i]),QString(text[i+2])));//если есть символ '-' добавлеем узел range
				i+=2;//и сдвигаем индекс на 2
			}
			else
				this->addChild(new node_symbol(QString(text[i])));//иначе добавляем ребенка symbol
		}
	}

	QString tagName()///<название тега
	{	return QString("sc");	}

	nodeType type()///<тип 
	{	return symbol_class;	}

	bool hasArg(QString arg)
	{	return (arg==QString("text")) ? true : false;	}


	/*!
	*\brief переопремеденная функция node::description
	*переопределяет функцию node::description
	*/
    QString description(const patternContainer & patterns, int num=-1, node * parent=NULL, QString form = QString())
	{
		QString current_pattern = this->pattern(patterns.getPatternFromType(this->type()),parent,form);
		QString insert;//строка которую вставляем
		static int new_num=num;//номер для подстановки в следующий узел
		new_num=(num<0) ? (num-1) : (num+1);//если номер отрицателен, ведем подсчет но в отрицательных значениях
		
		int pos = current_pattern.indexOf("$text");//позиция найденной подстроки
		if(pos==-1)
			throw QString("pattern for symbol_class_negative must contain $text");
		
		//обходим детей
		for(int i=0;i<childs.count();++i)
		{
			insert.append(childs[i]->description(patterns,new_num,this,form));
			if(i+1!=childs.count())
				insert.append(", ");
		}
		current_pattern.replace(pos,5,insert);//заменяем на внутренний формат подстановки qt

		//номер узла
		if(num>=0)
			current_pattern = QString("<%1>%2</%1>").arg(num).arg(current_pattern);

		return current_pattern;
	}
};

/*!
 * \brief Узел: [^symb]
 * Класс для определения узла типа [^symb]
 */
class node_symbol_class_negative :	public node
{
public:

	node_symbol_class_negative(QString text)
	{
		int _size = text.size();
		for(int i=0;i<_size;++i)
		{
			if(i+3<=_size && text[i+1]=='-')
			{
				this->addChild(new node_range(QString(text[i]),QString(text[i+2])));//если есть символ '-' добавлеем узел range
				i+=2;//и сдвигаем индекс на 2
			}
			else
				this->addChild(new node_symbol(QString(text[i])));//иначе добавляем ребенка symbol
		}
	}

	QString tagName()///<название тега
	{	return QString("scn");	}

	nodeType type()///<тип 
	{	return symbol_class_negative;	}

	bool hasArg(QString arg)
	{	return (arg==QString("text")) ? true : false;	}
	
	/*!
	*\brief переопремеденная функция node::description
	*переопределяет функцию node::description
	*/
    QString description(const patternContainer & patterns, int num=-1, node * parent=NULL, QString form = QString())
	{
		QString current_pattern = this->pattern(patterns.getPatternFromType(this->type()),parent,form);
		QString insert;//строка которую вставляем
		static int new_num=num;//номер для подстановки в следующий узел
		new_num=(num<0) ? (num-1) : (num+1);//если номер отрицателен, ведем подсчет но в отрицательных значениях
		
		int pos = current_pattern.indexOf("$text");//позиция найденной подстроки
		if(pos==-1)
			throw QString("pattern for symbol_class_negative must contain $text");
		
		//обходим детей
		for(int i=0;i<childs.count();++i)
		{
			insert.append(childs[i]->description(patterns,new_num,this,form));
			if(i+1!=childs.count())
				insert.append(", ");
		}
		current_pattern.replace(pos,5,insert);//заменяем на внутренний формат подстановки qt

		//номер узла
		if(num>=0)
			current_pattern = QString("<%1>%2</%1>").arg(num).arg(current_pattern);

		return current_pattern;
	}

};

/*!
 * \brief Узел: \\n (1 до 99)
 * Класс для определения узла типа \\n (1 до 99)
 */
class node_link :	public node
{
public:
	//QString n;

	node_link(QString _n)
	{	n=_n;}

	QString tagName()///<название тега
	{	return QString("link");	}

	nodeType type()///<тип 
	{	return link;	}

	bool hasArg(QString arg)
	{	return (arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: \\а
 * Класс для определения узла типа \\а
 */
class node_operand_a :	public node
{
public:

	node_operand_a()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("oa");	}

	nodeType type()///<тип 
	{	return operand_a;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\е
 * Класс для определения узла типа \\е
 */
class node_operand_e :	public node
{
public:

	node_operand_e()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("oe");	}

	nodeType type()///<тип 
	{	return operand_e;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\n
 * Класс для определения узла типа \\n
 */
class node_operand_n :	public node
{
public:

	node_operand_n()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("on");	}

	nodeType type()///<тип 
	{	return operand_n;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\t
 * Класс для определения узла типа \\t
 */
class node_operand_t :	public node
{
public:

	node_operand_t()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ot");	}

	nodeType type()///<тип 
	{	return operand_t;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: \\ddd
 * Класс для определения узла типа \\ddd
 */
class node_operand_8 :	public node
{
public:
	//QString n;

	node_operand_8(QString _n)
	{	n=_n;}

	QString tagName()///<название тега
	{	return QString("o8");	}

	nodeType type()///<тип 
	{	return operand_8;	}

	bool hasArg(QString arg)
	{	return (arg==QString("n")) ? true : false;	}
};

/*!
 * \brief Узел: \\xhh
 * Класс для определения узла типа \\xhh
 */
class node_operand_16 :	public node
{
public:
	//QString n;

	node_operand_16(QString _n)
	{	n=_n;}

	QString tagName()///<название тега
	{	return QString("o16");	}

	nodeType type()///<тип 
	{	return operand_16;	}

	bool hasArg(QString arg)
	{	return (arg==QString("n")) ? true : false;	}
};

/*!
 * \brief Узел: пустота
 * Класс для определения узла типа пустота
 */
class node_empty :	public node
{
public:
	node_empty()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("empty");	}

	nodeType type()///<тип 
	{	return empty;	}

	bool hasArg(QString arg)
	{	return false;	}
};

/*!
 * \brief Узел: text
 * Класс для определения узла типа text
 */
class node_otext :	public node
{
public:
	//QString text;

	node_otext(QString _text)
	{ text=_text;	}

	QString tagName()///<название тега
	{	return QString("t");	}

	nodeType type()///<тип 
	{	return otext;	}

	bool hasArg(QString arg)
	{	return (arg==QString("text")) ? true : false;	}
};
#pragma warning( default : 4100 )