#include "enemy.hpp"
#include <SDL.h>
#pragma once

//Pink inherits from Enemy Class

class Blue : public Enemy 
{
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets) override;
};
