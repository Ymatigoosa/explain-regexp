#include "patterncontainer.h"

patternContainer::patternContainer()
{
}

void patternContainer::addDefault(QString &tag, QString pattern)
{
	const QMap<QString,nodeType> &_tags=buildTagsMap();//�����: ���-���
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
	if(item.type == 0)
		return;//������ �� �������� �� ��� ������ ����
	const QMap<QString,nodeType> &_tags=buildTagsMap(); //�����: ���-���
	nodeType _currentType;
	variant *_variantPointer;	//��������� �� �������������� ������ � �������

	allVariants.append(item);	//��������� � ������ �������������� ��������
	_variantPointer = &(allVariants.last()); //�������� �������� �� ����������� ���������

	QMap<QString,nodeType>::iterator i=_tags.begin();
	while(i != _tags.end()) 
	{
		_currentType = i.value();// ���������� ������� ���
		if((_currentType & item.type) != 0) //���� ������ �������� ��� �������� ����
		{
			if(nodePatterns.contains(_currentType)) //���� ��� �������� ���� ��������� ��� ����������
			{
				nodePatterns[_currentType].variantPatterns.append(_variantPointer);//����� � ��� ���������� ������
			}
			else	//����� ������� ����� ��������� � ��������� � ������
			{
				nodePattern _newNodePattern;
				_newNodePattern.variantPatterns.append(_variantPointer);
				nodePatterns.insert(_currentType, _newNodePattern);
			}
		}
		++i;
	}
}

nodePattern patternContainer::getPatternFromType(nodeType type)
{
	return nodePatterns[type];
}