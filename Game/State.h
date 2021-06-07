#ifndef STATE_H
#define STATE_H

#include <cstdint>

class State
{
public:
    enum
    {
        MainMenu,
        Settings,
        Editor
    };

    State();
    ~State();
    size_t IsState();
    void Set(size_t Value);

private:
    size_t state;
};

#endif // STATE_H