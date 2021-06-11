#include "Skills.h"

int Skills::Get(size_t Index)
{
	return data.at(Index);
}

void Skills::Set(size_t Index, int Value)
{
	data.at(Index) = Value;
}