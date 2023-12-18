#include "enemy.hpp"
#include <SDL.h>
#pragma once

//Pink inherits from Enemy Class

class Pink : public Enemy 
{
    private:
        Unit pink= {{439,250,39,37}, {701, 228, 30, 30}};
        Unit pink2= {{439,250,39,37}, {701, 228, 30, 30}};
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets) override;
        Unit& pinkgetter();
};
