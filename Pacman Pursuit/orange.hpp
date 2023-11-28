#include "enemy.hpp"
#include <SDL.h>
#pragma once

//Orange inherits from Enemy Class

class Orange : public Enemy 
{
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets) override;
};
