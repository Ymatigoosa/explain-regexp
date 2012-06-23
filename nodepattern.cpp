#include "nodepattern.h"

nodePattern::nodePattern()
{
}
nodePattern::nodePattern(const nodePattern &_other)
{
	defaultPattern = _other.defaultPattern;
	variantPatterns = _other.variantPatterns;
}