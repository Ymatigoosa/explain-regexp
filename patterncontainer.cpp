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

}