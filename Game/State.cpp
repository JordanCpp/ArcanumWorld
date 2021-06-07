#include "State.h"

State::State():
    state(State::Editor)
{
}

State::~State()
{
}

size_t State::IsState()
{
    return state;
}

void State::Set(size_t Value)
{
    state = Value;
}
