#include <SDL.h>
#pragma once
#include <SDL_ttf.h>
#include "game.hpp"

class Death
{
    private:
        int value;
    public:
        void operator++();
        void display();
        Death();

        int valueget();
};
