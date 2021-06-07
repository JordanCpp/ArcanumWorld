#include "Critter.h"

Critter::Critter()
{
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