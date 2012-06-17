#include "patterncontainer.h"

patternContainer::patternContainer()
{
}

void patternContainer::addDefault(QString &tag, QString pattern)
{
	const QMap<QString,nodeType> &_tags=buildTagsMap();//карта: тег-тип
	nodeType _currentType;
	QString *_defaultPointer;		//указатель на стандартный шаблон в массиве

	if(_tags.contains(tag))			//если переданный тег есть в списке тегов
		_currentType = _tags[tag];	//получаем соответсвующий тип
	else							//иначе - выходим из функции
		return;
	defaults.append(pattern);		//добавляем шаблон в массив defaults
	_defaultPointer = &(defaults.last());//получаем указатель для nodePattern структуры

	if(nodePatterns.contains(_currentType)) //если для текущего типа структура уже определена
	{
		nodePatterns[_currentType].defaultPattern = _defaultPointer;//пишем в нее стандартный шаблон
	}
	else	//иначе создаем новую структуры и добавляем в массив
	{
		nodePattern _newNodePattern;
		_newNodePattern.defaultPattern = _defaultPointer;
		nodePatterns.insert(_currentType, _newNodePattern);
	}
}

void patternContainer::addVariant(variant item)
{
	if(item.type == 0)
		return;//шаблон не пригоден ни для одного узла
	const QMap<QString,nodeType> &_tags=buildTagsMap(); //карта: тег-тип
	nodeType _currentType;
	variant *_variantPointer;	//указатель на альтернативный шаблон в массиве

	allVariants.append(item);	//добавляем в массив альтернативных шаблонов
	_variantPointer = &(allVariants.last()); //получаем уазатель на добавленную структуру

	QMap<QString,nodeType>::iterator i=_tags.begin();
	while(i != _tags.end()) 
	{
		_currentType = i.value();// запонимаем текущий тип
		if((_currentType & item.type) != 0) //если шаблон применим для текущего типа
		{
			if(nodePatterns.contains(_currentType)) //если для текущего типа структура уже определена
			{
				nodePatterns[_currentType].variantPatterns.append(_variantPointer);//пишем в нее переданный шаблон
			}
			else	//иначе создаем новую структуры и добавляем в массив
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