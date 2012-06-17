#ifndef PATTERNCONTAINER_H
#define PATTERNCONTAINER_H
#include "variant.h"
#include "nodeType.h"
#include "nodepattern.h"
#include <QStringList>
#include <QMap>

const QMap<QString,nodeType> & buildTagsMap();

/*!
 * \brief �����, ���������� ������ ���� ��������
 * �����, ���������� ������ ���� �������� � ����������� ��������� ������ �������� ��� ������������� ����
 */
class patternContainer
{
public:
	QStringList defaults; ///<������ ����������� ��������, 
    QList<variant> allVariants; ///<������ �������������� ��������
	QMap<nodeType,nodePattern> nodePatterns;///<������ �������� �� �����, ���� � ��� ����, �������� � ������ ��������.
	
	patternContainer();	///<����������� �� ���������

	/*!
	 * ���������� ������������ ������� � defaults � � ��������������� ������ nodePatterns
	 * \param[in] tag	�������� ����
	 * \param[in] pattern	������
	 */
	void addDefault(QString &tag, QString pattern);

	/*!
	 * ���������� ��������������� �������� ������� � allVariants � � ��������������� ������ nodePatterns, �������� ���� item.type.
	 * \param[in] item ����������� ������
	 */
	void addVariant(variant item);

	/*!
	 *  ���������� ������ �������� ��� �������� ����
	 * \param[in] type ��������� ��� ����
	 * \return ������ �� ������ �������� �� ���������� nodePatterns
	 */
	nodePattern * getPatternFromType(nodeType type);
};

#endif // PATTERNCONTAINER_H
