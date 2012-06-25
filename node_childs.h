/*!
 * \file node_childs.h
 * �������� �������� ������� ����������� node
 */
#pragma once
#include "node.h"
#include "nodeType.h"
#pragma warning( disable : 4100 )

/*!
 * \brief ����: {m,n}
 * ����� ��� ����������� ���� ���� {m,n}
 */
class node_quantifier_mn :	public node
{
public:
	//QString m;
	//QString n;

	node_quantifier_mn(QString _m,QString _n)
	{ m=_m;n=_n;	}

	QString tagName() const///<�������� ����
	{	return QString("kmn");	}

	nodeType type() const///<��� 
	{	return quantifier_mn;	}

	bool hasArg(QString arg) const
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m}
 * ����� ��� ����������� ���� ���� {m}
 */
class node_quantifier_m :	public node
{
public:
	//QString m;

	node_quantifier_m(QString _m)
	{ m=_m;	}

	QString tagName() const///<�������� ����
	{	return QString("km");	}
	nodeType type() const///<��� 
	{	return quantifier_m;	}
	bool hasArg(QString arg) const
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief ����: {,n}
 * ����� ��� ����������� ���� ���� {,n}
 */
class node_quantifier_0n :	public node
{
public:
	//QString n;


	node_quantifier_0n(QString _n)///<����������� �� ���������
	{	n=_n;}

	QString tagName() const///<�������� ����
	{	return QString("kxn");	}

	nodeType type() const///<��� 
	{	return quantifier_0n;	}

	bool hasArg(QString arg) const
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m,}
 * ����� ��� ����������� ���� ���� {m,}
 */
class node_quantifier_m0 :	public node
{
public:
	//QString m;

	node_quantifier_m0(QString _m)
	{	m=_m;}

	QString tagName() const///<�������� ����
	{	return QString("kmx");	}

	nodeType type() const///<��� 
	{	return quantifier_m0;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("ks");	}

	nodeType type() const///<��� 
	{	return quantifier_star;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("kp");	}

	nodeType type() const///<��� 
	{	return quantifier_plus;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("kq");	}

	nodeType type() const///<��� 
	{	return quantifier_question;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: {m,n}+
 * ����� ��� ����������� ���� ���� {m,n}+
 */
class node_quantifier_mn_plus :	public node
{
public:
	//QString n;
	//QString m;

	node_quantifier_mn_plus(QString _m,QString _n)
	{	m=_m;n=_n;}

	QString tagName() const///<�������� ����
	{	return QString("kmnp");	}

	nodeType type() const///<��� 
	{	return quantifier_mn_plus;	}

	bool hasArg(QString arg) const
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m}+
 * ����� ��� ����������� ���� ���� {m}+
 */
class node_quantifier_m_plus :	public node
{
public:
	//QString m;

	node_quantifier_m_plus(QString _m)
	{	m=_m;}

	QString tagName() const///<�������� ����
	{	return QString("kmp");	}

	nodeType type() const///<��� 
	{	return quantifier_m_plus;	}

	bool hasArg(QString arg) const
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief ����: {,n}+
 * ����� ��� ����������� ���� ���� {,n}+
 */
class node_quantifier_0n_plus :	public node
{
public:
	//QString n;

	node_quantifier_0n_plus(QString _n)
	{	n=_n;}

	QString tagName() const///<�������� ����
	{	return QString("kxnp");	}

	nodeType type() const///<��� 
	{	return quantifier_0n_plus;	}

	bool hasArg(QString arg) const
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m,}+
 * ����� ��� ����������� ���� ���� {m,}+
 */
class node_quantifier_m0_plus :	public node
{
public:
	//QString m;

	node_quantifier_m0_plus(QString _m)
	{	m=_m;}

	QString tagName() const///<�������� ����
	{	return QString("kmxp");	}

	nodeType type() const///<��� 
	{	return quantifier_m0_plus;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("ksp");	}

	nodeType type() const///<��� 
	{	return quantifier_star_plus;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("kpp");	}

	nodeType type() const///<��� 
	{	return quantifier_plus_plus;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("kqp");	}

	nodeType type() const///<��� 
	{	return quantifier_question_plus;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: {m,n}?
 * ����� ��� ����������� ���� ���� {m,n}?
 */
class node_quantifier_mn_question :	public node
{
public:
	//QString n;
	//QString m;

	node_quantifier_mn_question(QString _m,QString _n)
	{	m=_m;n=_n;}

	QString tagName() const///<�������� ����
	{	return QString("kmnq");	}

	nodeType type() const///<��� 
	{	return quantifier_mn_question;	}

	bool hasArg(QString arg) const
	{	return ( arg==QString("m") || arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m}?
 * ����� ��� ����������� ���� ���� {m}?
 */
class node_quantifier_m_question :	public node
{
public:
	//QString m;

	node_quantifier_m_question(QString _m)
	{	m=_m;}

	QString tagName() const///<�������� ����
	{	return QString("kmq");	}

	nodeType type() const///<��� 
	{	return quantifier_m_question;	}

	bool hasArg(QString arg) const
	{	return ( arg==QString("m") ) ? true : false;	}
};

/*!
 * \brief ����: {,n}?
 * ����� ��� ����������� ���� ���� {,n}?
 */
class node_quantifier_0n_question :	public node
{
public:
	//QString n;

	node_quantifier_0n_question(QString _n)
	{	n=_n;}

	QString tagName() const///<�������� ����
	{	return QString("kxnq");	}

	nodeType type() const///<��� 
	{	return quantifier_0n_question;	}

	bool hasArg(QString arg) const
	{	return ( arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: {m,}?
 * ����� ��� ����������� ���� ���� {m,}?
 */
class node_quantifier_m0_question :	public node
{
public:
	//QString m;

	node_quantifier_m0_question(QString _m)///<����������� �� ���������
	{	m=_m;}

	QString tagName() const///<�������� ����
	{	return QString("kmxq");	}

	nodeType type() const///<��� 
	{	return quantifier_m0_question;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("ksq");	}

	nodeType type() const///<��� 
	{	return quantifier_star_question;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("kpq");	}

	nodeType type() const///<��� 
	{	return quantifier_plus_question;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("kqq");	}

	nodeType type() const///<��� 
	{	return quantifier_question_question;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("con");	}

	nodeType type() const///<��� 
	{	return concatenation;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("or");	}

	nodeType type() const///<��� 
	{	return oor;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("g");	}

	nodeType type() const///<��� 
	{	return group;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("gq");	}

	nodeType type() const///<��� 
	{	return group_question;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("go");	}

	nodeType type() const///<��� 
	{	return group_once;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("cm");	}

	nodeType type() const///<��� 
	{	return condition_mask;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("cmy");	}

	nodeType type() const///<��� 
	{	return condition_mask_yes;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("cf");	}

	nodeType type() const///<��� 
	{	return condition_forward;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("cfn");	}

	nodeType type() const///<��� 
	{	return condition_forward_negative;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("cb");	}

	nodeType type() const///<��� 
	{	return condition_back;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("cbn");	}

	nodeType type() const///<��� 
	{	return condition_back_negative;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("mi");	}

	nodeType type() const///<��� 
	{	return modifier_i;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("ms");	}

	nodeType type() const///<��� 
	{	return modifier_s;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("mu");	}

	nodeType type() const///<��� 
	{	return modifier_u;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("mm");	}

	nodeType type() const///<��� 
	{	return modifier_m;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("ad");	}

	nodeType type() const///<��� 
	{	return assert_d;	}

	bool hasArg(QString arg) const
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

	QString tagName() const///<�������� ����
	{	return QString("ac");	}

	nodeType type() const///<��� 
	{	return assert_cap;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\b
 * ����� ��� ����������� ���� ���� \\b
 */
class node_assert_b :	public node
{
public:

	node_assert_b()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("ab");	}

	nodeType type() const///<��� 
	{	return assert_b;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\�
 * ����� ��� ����������� ���� ���� \\�
 */
class node_assert_b_big :	public node
{
public:

	node_assert_b_big()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("abb");	}

	nodeType type() const///<��� 
	{	return assert_b_big;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\�
 * ����� ��� ����������� ���� ���� \\�
 */
class node_assert_a_big :	public node
{
public:

	node_assert_a_big()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("aab");	}

	nodeType type() const///<��� 
	{	return assert_a_big;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\Z
 * ����� ��� ����������� ���� ���� \\Z
 */
class node_assert_z_big :	public node
{
public:

	node_assert_z_big()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("azb");	}

	nodeType type() const///<��� 
	{	return assert_z_big;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\z
 * ����� ��� ����������� ���� ���� \\z
 */
class node_assert_z :	public node
{
public:

	node_assert_z()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("az");	}

	nodeType type() const///<��� 
	{	return assert_z;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\d
 * ����� ��� ����������� ���� ���� \\d
 */
class node_operand_d :	public node
{
public:

	node_operand_d()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("od");	}

	nodeType type() const///<��� 
	{	return operand_d;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\D
 * ����� ��� ����������� ���� ���� \\D
 */
class node_operand_d_big :	public node
{
public:

	node_operand_d_big()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("odb");	}

	nodeType type() const///<��� 
	{	return operand_d_big;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\s
 * ����� ��� ����������� ���� ���� \\s
 */
class node_operand_s :	public node
{
public:

	node_operand_s()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("os");	}

	nodeType type() const///<��� 
	{	return operand_s;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\S
 * ����� ��� ����������� ���� ���� \\S
 */
class node_operand_s_big :	public node
{
public:

	node_operand_s_big()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("osb");	}

	nodeType type() const///<��� 
	{	return operand_s_big;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\w
 * ����� ��� ����������� ���� ���� \\w
 */
class node_operand_w :	public node
{
public:

	node_operand_w()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("ow");	}

	nodeType type() const///<��� 
	{	return operand_w;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\W
 * ����� ��� ����������� ���� ���� \\W
 */
class node_operand_w_big :	public node
{
public:

	node_operand_w_big()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("owb");	}

	nodeType type() const///<��� 
	{	return operand_w_big;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: .
 * ����� ��� ����������� ���� ���� .
 */
class node_dot :	public node
{
public:

	node_dot()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("dot");	}

	nodeType type() const///<��� 
	{	return dot;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: a-z(������ [ ])
 * ����� ��� ����������� ���� ���� a-z(������ [ ])
 */
class node_range :	public node
{
public:
	node_range(QString _start,QString _end)
	{ m=_start;	n=_end;	}

	QString tagName() const///<�������� ����
	{	return QString("range");	}

	nodeType type() const///<��� 
	{	return range;	}

	bool hasArg(QString arg) const
	{	return (arg==QString("start") || arg==QString("end")) ? true : false;	}
};

/*!
 * \brief ����: ������(������ [ ])
 * ����� ��� ����������� ���� ���� ������(������ [ ])
 */
class node_symbol :	public node
{
public:
	//QString text;

	node_symbol(QString _text)
	{	text=_text;}

	QString tagName() const///<�������� ����
	{	return QString("symbol");	}

	nodeType type() const///<��� 
	{	return symbol;	}

	bool hasArg(QString arg) const
	{	return (arg==QString("text") ) ? true : false;	}
};

/*!
 * \brief ����: [symb]
 * ����� ��� ����������� ���� ���� [symb]
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
				this->addChild(new node_range(QString(text[i]),QString(text[i+2])));//���� ���� ������ '-' ��������� ���� range
				i+=2;//� �������� ������ �� 2
			}
			else
				this->addChild(new node_symbol(QString(text[i])));//����� ��������� ������� symbol
		}
	}

	QString tagName() const///<�������� ����
	{	return QString("sc");	}

	nodeType type() const///<��� 
	{	return symbol_class;	}

	bool hasArg(QString arg) const
	{	return (arg==QString("text")) ? true : false;	}


	/*!
	*\brief ���������������� ������� node::description
	*�������������� ������� node::description
	*/
    QString description(const patternContainer & patterns, int num=-1,node * parent=NULL, QString form = QString()) 
	{
		QString current_pattern = this->pattern(patterns.getPatternFromType(this->type()),parent,form);
		QString insert;//������ ������� ���������
		static int new_num=num;//����� ��� ����������� � ��������� ����
		new_num=(num<0) ? (num-1) : (num+1);//���� ����� �����������, ����� ������� �� � ������������� ���������
		
		int pos = current_pattern.indexOf("$text");//������� ��������� ���������
		if(pos==-1)
			throw QString("pattern for symbol_class must contain $text");
		
		//������� �����
		for(int i=0;i<childs.count();++i)
		{
			insert.append(childs[i]->description(patterns,new_num,this,form));
			if(i+1!=childs.count())
				insert.append(", ");
		}
		current_pattern.replace(pos,5,insert);//�������� �� ���������� ������ ����������� qt

		//����� ����
		if(num>=0)
			current_pattern = QString("<%1>%2</%1>").arg(num).arg(current_pattern);

		return current_pattern;
	}
};

/*!
 * \brief ����: [^symb]
 * ����� ��� ����������� ���� ���� [^symb]
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
				this->addChild(new node_range(QString(text[i]),QString(text[i+2])));//���� ���� ������ '-' ��������� ���� range
				i+=2;//� �������� ������ �� 2
			}
			else
				this->addChild(new node_symbol(QString(text[i])));//����� ��������� ������� symbol
		}
	}

	QString tagName() const///<�������� ����
	{	return QString("scn");	}

	nodeType type() const///<��� 
	{	return symbol_class_negative;	}

	bool hasArg(QString arg) const
	{	return (arg==QString("text")) ? true : false;	}
	
	/*!
	*\brief ���������������� ������� node::description
	*�������������� ������� node::description
	*/
    QString description(const patternContainer & patterns, int num=-1, node * parent=NULL, QString form = QString())
	{
		QString current_pattern = this->pattern(patterns.getPatternFromType(this->type()),parent,form);
		QString insert;//������ ������� ���������
		static int new_num=num;//����� ��� ����������� � ��������� ����
		new_num=(num<0) ? (num-1) : (num+1);//���� ����� �����������, ����� ������� �� � ������������� ���������
		
		int pos = current_pattern.indexOf("$text");//������� ��������� ���������
		if(pos==-1)
			throw QString("pattern for symbol_class_negative must contain $text");
		
		//������� �����
		for(int i=0;i<childs.count();++i)
		{
			insert.append(childs[i]->description(patterns,new_num,this,form));
			if(i+1!=childs.count())
				insert.append(", ");
		}
		current_pattern.replace(pos,5,insert);//�������� �� ���������� ������ ����������� qt

		//����� ����
		if(num>=0)
			current_pattern = QString("<%1>%2</%1>").arg(num).arg(current_pattern);

		return current_pattern;
	}

};

/*!
 * \brief ����: \\n (1 �� 99)
 * ����� ��� ����������� ���� ���� \\n (1 �� 99)
 */
class node_link :	public node
{
public:
	//QString n;

	node_link(QString _n)
	{	n=_n;}

	QString tagName() const///<�������� ����
	{	return QString("link");	}

	nodeType type() const///<��� 
	{	return link;	}

	bool hasArg(QString arg) const
	{	return (arg==QString("n") ) ? true : false;	}
};

/*!
 * \brief ����: \\�
 * ����� ��� ����������� ���� ���� \\�
 */
class node_operand_a :	public node
{
public:

	node_operand_a()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("oa");	}

	nodeType type() const///<��� 
	{	return operand_a;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\�
 * ����� ��� ����������� ���� ���� \\�
 */
class node_operand_e :	public node
{
public:

	node_operand_e()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("oe");	}

	nodeType type() const///<��� 
	{	return operand_e;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\n
 * ����� ��� ����������� ���� ���� \\n
 */
class node_operand_n :	public node
{
public:

	node_operand_n()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("on");	}

	nodeType type() const///<��� 
	{	return operand_n;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\t
 * ����� ��� ����������� ���� ���� \\t
 */
class node_operand_t :	public node
{
public:

	node_operand_t()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("ot");	}

	nodeType type() const///<��� 
	{	return operand_t;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: \\ddd
 * ����� ��� ����������� ���� ���� \\ddd
 */
class node_operand_8 :	public node
{
public:
	//QString n;

	node_operand_8(QString _n)
	{	n=_n;}

	QString tagName() const///<�������� ����
	{	return QString("o8");	}

	nodeType type() const///<��� 
	{	return operand_8;	}

	bool hasArg(QString arg) const
	{	return (arg==QString("n")) ? true : false;	}
};

/*!
 * \brief ����: \\xhh
 * ����� ��� ����������� ���� ���� \\xhh
 */
class node_operand_16 :	public node
{
public:
	//QString n;

	node_operand_16(QString _n)
	{	n=_n;}

	QString tagName() const///<�������� ����
	{	return QString("o16");	}

	nodeType type() const///<��� 
	{	return operand_16;	}

	bool hasArg(QString arg) const
	{	return (arg==QString("n")) ? true : false;	}
};

/*!
 * \brief ����: �������
 * ����� ��� ����������� ���� ���� �������
 */
class node_empty :	public node
{
public:
	node_empty()///<����������� �� ���������
	{	}

	QString tagName() const///<�������� ����
	{	return QString("empty");	}

	nodeType type() const///<��� 
	{	return empty;	}

	bool hasArg(QString arg) const
	{	return false;	}
};

/*!
 * \brief ����: text
 * ����� ��� ����������� ���� ���� text
 */
class node_otext :	public node
{
public:
	//QString text;

	node_otext(QString _text)
	{ text=_text;	}

	QString tagName() const///<�������� ����
	{	return QString("t");	}

	nodeType type() const///<��� 
	{	return otext;	}

	bool hasArg(QString arg) const
	{	return (arg==QString("text")) ? true : false;	}
};
#pragma warning( default : 4100 )