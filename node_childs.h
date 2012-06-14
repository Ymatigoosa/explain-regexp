/*!
 * \file node_childs.h
 * Содержит описание классив наследников node
 */
#pragma once
#include "node.h"
#include "nodeType.h"


/*enum nodeType : unsigned long long {
= 0x1,
 = 0x2,
 = 0x4,
 = 0x8,
 = 0x10,
 = 0x20,
 = 0x40,
 = 0x80,
 = 0x100,
 = 0x200,
 = 0x400,
 = 0x800,
 = 0x1000,
 = 0x2000,
 = 0x4000,
 = 0x8000,
 = 0x10000,
 = 0x20000,
 = 0x40000,
quantifier_plus_question = 0x80000,
quantifier_question_question = 0x100000,
concatenation = 0x200000,
oor = 0x400000,
group = 0x800000,
group_question = 0x1000000,
group_once = 0x2000000,
condition_mask = 0x4000000,
condition_mask_yes = 0x8000000,
modifier_i = 0x10000000,
modifier_s = 0x20000000,
modifier_u = 0x40000000,
modifier_m = 0x80000000,
condition_forward = 0x100000000,
condition_forward_negative = 0x200000000,
condition_back = 0x400000000,
condition_back_negative = 0x800000000,
assert_d = 0x1000000000,
assert_cap = 0x2000000000,
assert_b = 0x4000000000,
assert_b_big = 0x8000000000,
assert_a_big = 0x10000000000,
assert_z_big = 0x20000000000,
assert_z = 0x40000000000,
operand_d = 0x80000000000,
operand_d_big = 0x100000000000,
operand_s = 0x200000000000,
operand_s_big = 0x400000000000,
operand_w = 0x800000000000,
operand_w_big = 0x1000000000000,
dot = 0x2000000000000,
symbol_class = 0x4000000000000,
symbol_class_negative = 0x8000000000000,
range = 0x10000000000000,
symbol = 0x20000000000000,
link = 0x40000000000000,
operand_a = 0x80000000000000,
operand_e = 0x100000000000000,
operand_n = 0x200000000000000,
operand_t = 0x400000000000000,
operand_8 = 0x800000000000000,
operand_16 = 0x1000000000000000,
empty = 0x2000000000000000,
text = 0x4000000000000000*/

/*!
 * \brief Узел: {m,n}
 * Класс для определения узла типа {m,n}
 */
class node_quantifier_mn :	public node
{
public:
	QString m;
	QString n;

	node_quantifier_mn()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kmn");	}

	nodeType type()///<тип 
	{	return quantifier_mn;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m}
 * Класс для определения узла типа {m}
 */
class node_quantifier_m :	public node
{
public:
	QString m;

	node_quantifier_m()///<конструктор по умолчанию
	{	}
	QString tagName()///<название тега
	{	return QString("km");	}
	nodeType type()///<тип 
	{	return quantifier_m;	}
	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: {,n}
 * Класс для определения узла типа {,n}
 */
class node_quantifier_0n :	public node
{
public:
	QString n;

	node_quantifier_0n()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kxn");	}

	nodeType type()///<тип 
	{	return quantifier_0n;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m,}
 * Класс для определения узла типа {m,}
 */
class node_quantifier_m0 :	public node
{
public:
	QString m;

	node_quantifier_m0()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kmx");	}

	nodeType type()///<тип 
	{	return quantifier_m0;	}

	bool hasArg(QString & arg)
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

	bool hasArg(QString & arg)
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

	bool hasArg(QString & arg)
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

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief Узел: {m,n}+
 * Класс для определения узла типа {m,n}+
 */
class node_quantifier_mn_plus :	public node
{
public:
	QString n;
	QString m;

	node_quantifier_mn_plus()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kmnp");	}

	nodeType type()///<тип 
	{	return quantifier_mn_plus;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m}+
 * Класс для определения узла типа {m}+
 */
class node_quantifier_m_plus :	public node
{
public:
	QString m;

	node_quantifier_m_plus()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kmp");	}

	nodeType type()///<тип 
	{	return quantifier_m_plus;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: {,n}+
 * Класс для определения узла типа {,n}+
 */
class node_quantifier_0n_plus :	public node
{
public:
	QString n;

	node_quantifier_0n_plus()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kxnp");	}

	nodeType type()///<тип 
	{	return quantifier_0n_plus;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m,}+
 * Класс для определения узла типа {m,}+
 */
class node_quantifier_m0_plus :	public node
{
public:
	QString m;

	node_quantifier_m0_plus()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kmxp");	}

	nodeType type()///<тип 
	{	return quantifier_m0_plus;	}

	bool hasArg(QString & arg)
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

	bool hasArg(QString & arg)
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

	bool hasArg(QString & arg)
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

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief Узел: {m,n}?
 * Класс для определения узла типа {m,n}?
 */
class node_quantifier_mn_question :	public node
{
public:
	QString n;
	QString m;

	node_quantifier_mn_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kmnq");	}

	nodeType type()///<тип 
	{	return quantifier_mn_question;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m}?
 * Класс для определения узла типа {m}?
 */
class node_quantifier_m_question :	public node
{
public:
	QString m;

	node_quantifier_m_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kmq");	}

	nodeType type()///<тип 
	{	return quantifier_m_question;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: {,n}?
 * Класс для определения узла типа {,n}?
 */
class node_quantifier_0n_question :	public node
{
public:
	QString n;

	node_quantifier_0n_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kxnq");	}

	nodeType type()///<тип 
	{	return quantifier_0n_question;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief Узел: {m,}?
 * Класс для определения узла типа {m,}?
 */
class node_quantifier_m0_question :	public node
{
public:
	QString m;

	node_quantifier_m0_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("kmxq");	}

	nodeType type()///<тип 
	{	return quantifier_m0_question;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief Узел: *?
 * Класс для определения узла типа *?
 */
class node_quantifier_star_question :	public node
{
public:
	QString m;

	node_quantifier_star_question()///<конструктор по умолчанию
	{	}

	QString tagName()///<название тега
	{	return QString("ksq");	}

	nodeType type()///<тип 
	{	return quantifier_star_question;	}

	bool hasArg(QString & arg)
	{	return false;	}
};