#include "enemy.hpp"
#include <SDL.h>
#pragma once

//Orange inherits from Enemy Class

class Orange : public Enemy 
{
    private:
        Unit orange= {{353,250,41,34}, {258, 302, 30, 30}};
        Unit orange2= {{353,250,41,34}, {258, 302, 30, 30}};
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets) override;
        Unit& Orangegetter();
};
