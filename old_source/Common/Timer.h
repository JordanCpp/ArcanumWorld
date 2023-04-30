#ifndef TIMER_H
#define TIMER_H

#include <cstdint>
#include <SDL2/SDL.h>

class Timer
{
public:
    Timer();
    ~Timer();
    void Start();
    void Update();
    bool Done();
private:
    size_t start;
    size_t period;
    bool done;
};

#endif // TIMER_H