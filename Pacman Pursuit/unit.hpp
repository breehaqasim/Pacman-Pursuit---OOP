#include <SDL.h>
#pragma once

//this is Base class

class Unit 
{
    public:
        SDL_Rect srcRect, moverRect;
        bool checkCollision(const Unit& other) const;
};
