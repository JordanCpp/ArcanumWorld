#ifndef _Objects_Critter_h_
#define _Objects_Critter_h_ 

#include "ScriptCritter.h"
#include "../Common/XmlReader.hpp"
#include "../Game/Stats.h"
#include "../Game/Skills.h"

class ScriptCritter;

class Critter
{
public:
	Critter(XmlReader* reader);
	void Init(ScriptCritter* ScriptCritterSource);
	~Critter();
	int Base(size_t Index);
	int Bonus(size_t Index);
	int Stat(size_t Index);
	void Base(size_t Index, int Value);
private:
	void LoadStats(XmlReader* Reader);
	ScriptCritter* script;
	Stats base_stats;
	Stats bonus_stats;
	Skills base_skills;
	Skills bonus_skills;
};

#endif