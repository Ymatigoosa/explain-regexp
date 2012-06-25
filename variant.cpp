#include "variant.h"

variant::variant()
{
	type = 0;
	parentType = 0;
	childiType << 0 << 0 << 0;
	childiContent << QString() << QString() << QString();
	childType = 0;
}
