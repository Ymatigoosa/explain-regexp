#include "patterncontainer.h"

patternContainer::patternContainer()
{
}
nodePattern * patternContainer::getPatternFromType(nodeType type)
{
	static nodePattern a;
	return &a;
}