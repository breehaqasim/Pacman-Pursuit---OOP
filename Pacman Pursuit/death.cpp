#include "death.hpp"
#include <iostream>
#include <SDL_ttf.h>
#include <SDL.h>
#include "game.hpp"
#pragma once

Death::Death()
{
    value=0;
}

void Death::operator ++()
{
    ++value;
}

void Death::display()
{
    std::cout<<value<<std::endl;
}

int Death::valueget()
{
    return value;
}
