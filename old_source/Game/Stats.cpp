#include "Stats.h"

int Stats::Get(size_t Index)
{
	return data.at(Index);
}

void Stats::Set(size_t Index, int Value)
{
	data.at(Index) = Value;
}