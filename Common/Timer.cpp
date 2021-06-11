#include "Timer.h"

Timer::Timer():
	start(0),
	period(0),
	done(false)
{
}

Timer::~Timer()
{
}

void Timer::Start()
{
	start = SDL_GetTicks();

	if (period >= 500)
	{
		done = true;
		period = 0;
	}
}

void Timer::Update()
{
	done = false;
	period += SDL_GetTicks() - start;
}

bool Timer::Done()
{
	return done;
}