#include "enemy.hpp"
#include <SDL.h>
#pragma once

//Purple inherits from Enemy Class
class Purple : public Enemy 
{
    private:
        Unit purple1= {{663,249,40,38}, {258, 375, 30, 30}};
        Unit purple2= {{596,250,40,37}, {258, 375 ,30, 30}};
    public:
        virtual void drawEnemy(SDL_Renderer* gRnderer, SDL_Texture* assets) override;
        Unit& purplegetter();
};
