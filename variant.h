#ifndef VARIANT_H
#define VARIANT_H
#include <QList>
#include <QString>

/*!
 * \brief �����, ���������� �������������� ������� ������� � ������� ��� ����������
 * �����, ���������� �������������� ������� ������� � ������� ��� ����������
 */
class variant
{
public:
	unsigned long long type;///<������� ������. �������� �� ��������� 0; 1 �� i ������� � ��� i �������� ��� �������������. ������ �������� � ������� emun nodeType
    unsigned long long parentType;///<���������� \ref type ��� ���� ��������
	QList<unsigned long long> childiType;///<���������� \ref type ��� ���� i-���� �������
	unsigned long long childType;///<���������� \ref type ��� ���� ������ �� ��������,
	QString content;///<���������� ���������  ��� �������� ���������� ���������� ����, ������ ������ �� ���������
	QString parentContent;///<���������� \ref content ��� ��������
	QList<QString> childiContent;///<���������� \ref content ��� i - �������
	QString form;///<��������� �����, ��������� ����� ����� $ � ����� � �������
	QString m;///<��� ��������������� � ������
	QString n;///<��� ���������������
	QString pattern;///<����� �������

	variant();
};

#endif // VARIANT_H
