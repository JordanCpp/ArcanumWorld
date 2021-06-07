#ifndef CRITTER_H
#define CRITTER_H

#include "../Game/Stats.h"

class Critter
{
public:
    Critter();
    ~Critter();
    int Base(size_t Index);
    int Bonus(size_t Index);
    int Stat(size_t Index);
private:
    Stats base;
    Stats bonus;
};

#endif // CRITTER_H