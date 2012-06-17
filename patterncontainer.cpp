#include "patterncontainer.h"

patternContainer::patternContainer()
{
}
nodePattern * patternContainer::getPatternFromType(nodeType type)
{
	static nodePattern a;
	return &a;
}

void patternContainer::addDefault(QString &tag, QString pattern)
{
	const QMap<QString,nodeType> &_tags=buildTagsMap();
	nodeType _currentType;
	QString *_defaultPointer;		//��������� �� ����������� ������ � �������

	if(_tags.contains(tag))			//���� ���������� ��� ���� � ������ �����
		_currentType = _tags[tag];	//�������� �������������� ���
	else							//����� - ������� �� �������
		return;
	defaults.append(pattern);		//��������� ������ � ������ defaults
	_defaultPointer = &(defaults.last());//�������� ��������� ��� nodePattern ���������

	if(nodePatterns.contains(_currentType)) //���� ��� �������� ���� ��������� ��� ����������
	{
		nodePatterns[_currentType].defaultPattern = _defaultPointer;//����� � ��� ����������� ������
	}
	else	//����� ������� ����� ��������� � ��������� � ������
	{
		nodePattern _newNodePattern;
		_newNodePattern.defaultPattern = _defaultPointer;
		nodePatterns.insert(_currentType, _newNodePattern);
	}
}

void patternContainer::addVariant(variant item)
{

}