#include "enemy.hpp"
#include <SDL.h>
#pragma once

//Blue inherits from Enemy Class

class Blue : public Enemy 
{
    private:
        Unit blue= {{519,250,41,37}, {400, 228, 30, 30}};
        Unit blue2= {{519,250,41,37}, {400, 228, 30, 30}};
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets) override;
        Unit& Bluegetter();
};
