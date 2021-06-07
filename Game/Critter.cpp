#include "Critter.h"

Critter::Critter(XmlReader* Reader, ResourceManager* Manager)
{
    LoadStats(Reader);
}

Critter::~Critter()
{
}

int Critter::Base(size_t Index)
{
    return base.Get(Index);
}

int Critter::Bonus(size_t Index)
{
    return bonus.Get(Index);
}

int Critter::Stat(size_t Index)
{
    int bs = Base(Index);
    int bn = Bonus(Index);

    if (bn > 0)
    {
        return bs + bn;
    }
    else if (bn < 0)
    {
        return bs - bn;
    }
    else
    {
        return bs;
    }
}

void Critter::Base(size_t Index, int Value)
{
    base.Set(Index, Value);
}

void Critter::LoadStats(XmlReader* Reader)
{
    Reader->NextOpening("Critter");
    Reader->NextOpening("Stats");

    Reader->NextNode("Strength");
    Base(Stats::Strength, Reader->ValueInt());

    Reader->NextNode("Constitution");
    Base(Stats::Constitution, Reader->ValueInt());

    Reader->NextNode("Dexterity");
    Base(Stats::Dexterity, Reader->ValueInt());

    Reader->NextNode("Beauty");
    Base(Stats::Beauty, Reader->ValueInt());

    Reader->NextNode("Intelligence");
    Base(Stats::Intelligence, Reader->ValueInt());

    Reader->NextNode("Willpower");
    Base(Stats::Willpower, Reader->ValueInt());

    Reader->NextNode("Perception");
    Base(Stats::Perception, Reader->ValueInt());

    Reader->NextNode("Charisma");
    Base(Stats::Charisma, Reader->ValueInt());

    Reader->NextClosing("Stats");
    Reader->NextClosing("Critter");
}