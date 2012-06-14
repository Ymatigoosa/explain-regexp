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
quantifier_0n = 0x4,
quantifier_m0 = 0x8,
quantifier_star = 0x10,
quantifier_plus = 0x20,
quantifier_question = 0x40,
quantifier_mn_plus = 0x80,
quantifier_m_plus = 0x100,
quantifier_0n_plus = 0x200,
quantifier_m0_plus = 0x400,
quantifier_star_plus = 0x800,
quantifier_plus_plus = 0x1000,
quantifier_question_plus = 0x2000,
quantifier_mn_question = 0x4000,
quantifier_m_question = 0x8000,
quantifier_0n_question = 0x10000,
quantifier_m0_question = 0x20000,
quantifier_star_question = 0x40000,
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
	node_quantifier_mn()///<конструктор по умолчанию
	{
	}
	QString tagName()///<название тега
	{
		return QString("kmn");
	}
	nodeType type()///<тип 
	{
		return quantifier_mn;
	}
	bool hasArg(QString & arg)
	{
		return ( arg==QString("m") || arg==QString("n") ) ? true : false;
	}
};

/*!
 * \brief Узел: {m}
 * Класс для определения узла типа {m}
 */
class node_quantifier_m :	public node
{
public:
	node_quantifier_m();///<конструктор по умолчанию
	{
	}
	QString tagName()///<название тега
	{
		return QString("km");
	}
	nodeType type()///<тип 
	{
		return quantifier_m;
	}
	bool hasArg(QString & arg)
	{
		return ( arg==QString("m") ) ? true : false;
	}
};

