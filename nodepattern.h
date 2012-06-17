#ifndef NODEPATTERN_H
#define NODEPATTERN_H
#include "variant.h"

/*!
 * \brief ������ �������� ��� ������������� ����.
 * �����, ������ �������� ��� ������������� ����. defaultPattern - ����������� ������. variantPatterns - ������ �������������� ��������
 */
class nodePattern
{
public:
    nodePattern();
	nodePattern(const nodePattern &);

	QString * defaultPattern; //!< ����������� ������;
	QList<variant *> variantPatterns; //!< ������ �������������� ��������.
};

#endif // NODEPATTERN_H
