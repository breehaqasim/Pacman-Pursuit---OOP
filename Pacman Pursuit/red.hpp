#include "enemy.hpp"
#include <SDL.h>
#pragma once

//Red inherits from Enemy Class
class Red : public Enemy 
{
    private:
        Unit red= {{596,250,40,37}, {258, 228, 30, 30}};
        Unit red2= {{596,250,40,37}, {258, 228, 30, 30}};
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets) override;
        Unit& redgetter();
};

