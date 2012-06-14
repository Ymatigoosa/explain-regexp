#ifndef NODEPATTERN_H
#define NODEPATTERN_H

/*!
 * \brief ������ �������� ��� ������������� ����
 * �����, ������ �������� ��� ������������� ����
 */
class nodePattern
{
public:
    nodePattern();

	QString * default; //!< ����������� ������;
	QList<variant *> variants; //!< ������ �������������� ��������.
};

#endif // NODEPATTERN_H
