#ifndef _Stat_h
#define _Stat_h

#include <array>

class Stats
{
public:
	enum
	{
		Strength,
		Constitution,
		Dexterity,
		Beauty,
		Intelligence,
		Willpower,
		Perception,
		Charisma,
		Max
	};

	int Get(size_t Index);
	void Set(size_t Index, int Value);
private:
	std::array<int, Stats::Max> data;
};

#endif