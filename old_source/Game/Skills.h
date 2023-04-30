#ifndef _Skills_h
#define _Skills_h

#include <array>

class Skills
{
public:
	enum
	{
		//Combat skills
		Bow,
		Dodge,
		Melee,
		Throwing,

		//Thieving skills
		Backstab,
		PickPocket,
		Prowling,
		SpotTrap,

		//Social skills
		Gambling,
		Haggle,
		Heal,
		Persuasion,

		//Technological skills
		Repair,
		Firearms,
		PickLocks,
		DisarmTraps,

		Max
	};

	int Get(size_t Index);
	void Set(size_t Index, int Value);
private:
	std::array<int, Skills::Max> data;
};

#endif