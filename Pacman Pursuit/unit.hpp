#include "unit.hpp"
#include <SDL.h>
#pragma once

//Enemy inherits from Unit
//it is also a "Base" class to Red,Blue,Orange,Pink Enemy Classes & an "Abstract" class

class Enemy : public Unit {
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets)=0;
};
