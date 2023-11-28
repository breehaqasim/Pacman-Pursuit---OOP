#include "enemy.hpp"
#include <SDL.h>
#pragma once

//Red inherits from Enemy Class

class Red : public Enemy 
{
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets) override;
};


