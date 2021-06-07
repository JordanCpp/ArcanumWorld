#ifndef TIMER_H
#define TIMER_H

#include <cstdint>

class Timer
{
public:
    Timer();
    ~Timer();

private:
    size_t start;
    size_t period;
};

#endif // TIMER_H
