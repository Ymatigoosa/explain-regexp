/*!
 * \file node_childs.h
 * �������� �������� ������� ����������� node
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
 = 0x80000,
 = 0x100000,
 = 0x200000,
 = 0x400000,
 = 0x800000,
 = 0x1000000,
 = 0x2000000,
 = 0x4000000,
 = 0x8000000,
 = 0x10000000,
 = 0x20000000,
 = 0x40000000,
 = 0x80000000,
 = 0x100000000,
 = 0x200000000,
 = 0x400000000,
 = 0x800000000,
 = 0x1000000000,
 = 0x2000000000,
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
 * \brief ����: {m,n}
 * ����� ��� ����������� ���� ���� {m,n}
 */
class node_quantifier_mn :	public node
{
public:
	QString m;
	QString n;

	node_quantifier_mn()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kmn");	}

	nodeType type()///<��� 
	{	return quantifier_mn;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m}
 * ����� ��� ����������� ���� ���� {m}
 */
class node_quantifier_m :	public node
{
public:
	QString m;

	node_quantifier_m()///<����������� �� ���������
	{	}
	QString tagName()///<�������� ����
	{	return QString("km");	}
	nodeType type()///<��� 
	{	return quantifier_m;	}
	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief ����: {,n}
 * ����� ��� ����������� ���� ���� {,n}
 */
class node_quantifier_0n :	public node
{
public:
	QString n;

	node_quantifier_0n()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kxn");	}

	nodeType type()///<��� 
	{	return quantifier_0n;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m,}
 * ����� ��� ����������� ���� ���� {m,}
 */
class node_quantifier_m0 :	public node
{
public:
	QString m;

	node_quantifier_m0()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kmx");	}

	nodeType type()///<��� 
	{	return quantifier_m0;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief ����: *
 * ����� ��� ����������� ���� ���� *
 */
class node_quantifier_star :	public node
{
public:
	node_quantifier_star()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("ks");	}

	nodeType type()///<��� 
	{	return quantifier_star;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: +
 * ����� ��� ����������� ���� ���� +
 */
class node_quantifier_plus :	public node
{
public:
	node_quantifier_plus()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kp");	}

	nodeType type()///<��� 
	{	return quantifier_plus;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: ?
 * ����� ��� ����������� ���� ���� ?
 */
class node_quantifier_question :	public node
{
public:
	node_quantifier_question()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kq");	}

	nodeType type()///<��� 
	{	return quantifier_question;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: {m,n}+
 * ����� ��� ����������� ���� ���� {m,n}+
 */
class node_quantifier_mn_plus :	public node
{
public:
	QString n;
	QString m;

	node_quantifier_mn_plus()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kmnp");	}

	nodeType type()///<��� 
	{	return quantifier_mn_plus;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m}+
 * ����� ��� ����������� ���� ���� {m}+
 */
class node_quantifier_m_plus :	public node
{
public:
	QString m;

	node_quantifier_m_plus()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kmp");	}

	nodeType type()///<��� 
	{	return quantifier_m_plus;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief ����: {,n}+
 * ����� ��� ����������� ���� ���� {,n}+
 */
class node_quantifier_0n_plus :	public node
{
public:
	QString n;

	node_quantifier_0n_plus()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kxnp");	}

	nodeType type()///<��� 
	{	return quantifier_0n_plus;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m,}+
 * ����� ��� ����������� ���� ���� {m,}+
 */
class node_quantifier_m0_plus :	public node
{
public:
	QString m;

	node_quantifier_m0_plus()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kmxp");	}

	nodeType type()///<��� 
	{	return quantifier_m0_plus;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief ����: *+
 * ����� ��� ����������� ���� ���� *+
 */
class node_quantifier_star_plus :	public node
{
public:
	node_quantifier_star_plus()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("ksp");	}

	nodeType type()///<��� 
	{	return quantifier_star_plus;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: ++
 * ����� ��� ����������� ���� ���� ++
 */
class node_quantifier_plus_plus :	public node
{
public:
	node_quantifier_plus_plus()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kpp");	}

	nodeType type()///<��� 
	{	return quantifier_plus_plus;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: ?+
 * ����� ��� ����������� ���� ���� ?+
 */
class node_quantifier_question_plus :	public node
{
public:
	node_quantifier_question_plus()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kqp");	}

	nodeType type()///<��� 
	{	return quantifier_question_plus;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: {m,n}?
 * ����� ��� ����������� ���� ���� {m,n}?
 */
class node_quantifier_mn_question :	public node
{
public:
	QString n;
	QString m;

	node_quantifier_mn_question()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kmnq");	}

	nodeType type()///<��� 
	{	return quantifier_mn_question;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m}?
 * ����� ��� ����������� ���� ���� {m}?
 */
class node_quantifier_m_question :	public node
{
public:
	QString m;

	node_quantifier_m_question()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kmq");	}

	nodeType type()///<��� 
	{	return quantifier_m_question;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief ����: {,n}?
 * ����� ��� ����������� ���� ���� {,n}?
 */
class node_quantifier_0n_question :	public node
{
public:
	QString n;

	node_quantifier_0n_question()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kxnq");	}

	nodeType type()///<��� 
	{	return quantifier_0n_question;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m,}?
 * ����� ��� ����������� ���� ���� {m,}?
 */
class node_quantifier_m0_question :	public node
{
public:
	QString m;

	node_quantifier_m0_question()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kmxq");	}

	nodeType type()///<��� 
	{	return quantifier_m0_question;	}

	bool hasArg(QString & arg)
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief ����: *?
 * ����� ��� ����������� ���� ���� *?
 */
class node_quantifier_star_question :	public node
{
public:

	node_quantifier_star_question()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("ksq");	}

	nodeType type()///<��� 
	{	return quantifier_star_question;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: +?
 * ����� ��� ����������� ���� ���� +?
 */
class node_quantifier_plus_question :	public node
{
public:

	node_quantifier_plus_question()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kpq");	}

	nodeType type()///<��� 
	{	return quantifier_plus_question;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: ??
 * ����� ��� ����������� ���� ���� ??
 */
class node_quantifier_question_question :	public node
{
public:

	node_quantifier_question_question()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("kqq");	}

	nodeType type()///<��� 
	{	return quantifier_question_question;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: ������������
 * ����� ��� ����������� ���� ���� ������������
 */
class node_concatenation :	public node
{
public:

	node_concatenation()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("con");	}

	nodeType type()///<��� 
	{	return concatenation;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: |
 * ����� ��� ����������� ���� ���� |
 */
class node_oor :	public node
{
public:

	node_oor()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("or");	}

	nodeType type()///<��� 
	{	return oor;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: ( )
 * ����� ��� ����������� ���� ���� ( )
 */
class node_group :	public node
{
public:

	node_group()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("g");	}

	nodeType type()///<��� 
	{	return group;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?: )
 * ����� ��� ����������� ���� ���� (?: )
 */
class node_group_question :	public node
{
public:

	node_group_question()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("gq");	}

	nodeType type()///<��� 
	{	return group_question;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?> )
 * ����� ��� ����������� ���� ���� (?> )
 */
class node_group_once :	public node
{
public:

	node_group_once()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("go");	}

	nodeType type()///<��� 
	{	return group_once;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?(�������) ���������1| ���������2)
 * ����� ��� ����������� ���� ���� (?(�������) ���������1| ���������2)
 */
class node_condition_mask :	public node
{
public:

	node_condition_mask()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("cm");	}

	nodeType type()///<��� 
	{	return condition_mask;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?(�������) ���������1)
 * ����� ��� ����������� ���� ���� (?(�������) ���������1)
 */
class node_condition_mask_yes :	public node
{
public:

	node_condition_mask_yes()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("cmy");	}

	nodeType type()///<��� 
	{	return condition_mask_yes;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?=text)
 * ����� ��� ����������� ���� ���� (?=text)
 */
class node_condition_forward :	public node
{
public:

	node_condition_forward()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("cf");	}

	nodeType type()///<��� 
	{	return condition_forward;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?!text)
 * ����� ��� ����������� ���� ���� (?!text)
 */
class node_condition_forward_negative :	public node
{
public:

	node_condition_forward_negative()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("cfn");	}

	nodeType type()///<��� 
	{	return condition_forward_negative;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?<=text)
 * ����� ��� ����������� ���� ���� (?<=text)
 */
class node_condition_back :	public node
{
public:

	node_condition_back()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("cb");	}

	nodeType type()///<��� 
	{	return condition_back;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?<!text)
 * ����� ��� ����������� ���� ���� (?<!text)
 */
class node_condition_back_negative :	public node
{
public:

	node_condition_back_negative()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("cbn");	}

	nodeType type()///<��� 
	{	return condition_back_negative;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?i)
 * ����� ��� ����������� ���� ���� (?i)
 */
class node_modifier_i :	public node
{
public:

	node_modifier_i()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("mi");	}

	nodeType type()///<��� 
	{	return modifier_i;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?s)
 * ����� ��� ����������� ���� ���� (?s)
 */
class node_modifier_s :	public node
{
public:

	node_modifier_s()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("ms");	}

	nodeType type()///<��� 
	{	return modifier_s;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?U)
 * ����� ��� ����������� ���� ���� (?U)
 */
class node_modifier_u :	public node
{
public:

	node_modifier_u()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("mu");	}

	nodeType type()///<��� 
	{	return modifier_u;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: (?m)
 * ����� ��� ����������� ���� ���� (?m)
 */
class node_modifier_m :	public node
{
public:

	node_modifier_m()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("mm");	}

	nodeType type()///<��� 
	{	return modifier_m;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: $
 * ����� ��� ����������� ���� ���� $
 */
class node_assert_d :	public node
{
public:

	node_assert_d()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("ad");	}

	nodeType type()///<��� 
	{	return assert_d;	}

	bool hasArg(QString & arg)
	{	return false;	}
};

/*!
 * \brief ����: ^
 * ����� ��� ����������� ���� ���� ^
 */
class node_assert_cap :	public node
{
public:

	node_assert_cap()///<����������� �� ���������
	{	}

	QString tagName()///<�������� ����
	{	return QString("ac");	}

	nodeType type()///<��� 
	{	return assert_cap;	}

	bool hasArg(QString & arg)
	{	return false;	}
};