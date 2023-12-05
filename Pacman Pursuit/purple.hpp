#include "enemy.hpp"
#include <SDL.h>
#pragma once

//Purple inherits from Enemy Class

class Purple : public Enemy 
{
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets) override;
};
