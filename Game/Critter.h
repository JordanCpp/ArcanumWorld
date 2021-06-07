#ifndef CRITTER_H
#define CRITTER_H

#include "../Game/Stats.h"
#include "ResourceManager.h"

class Critter
{
public:
    Critter(XmlReader * Reader, ResourceManager * Manager);
    ~Critter();
    int Base(size_t Index);
    int Bonus(size_t Index);
    int Stat(size_t Index);
    void Base(size_t Index, int Value);
private:
    void LoadStats(XmlReader * Reader);
    Stats base;
    Stats bonus;
};

#endif // CRITTER_H