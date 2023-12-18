#include "unit.hpp"
#pragma once
#include <SDL.h>

//Pacman inherits from Unit

class Pacman : public Unit 
{
    private:
        Unit p = {{305,174,37,40}, {310, 174, 30, 30}};
    public:
        void movePacman(SDL_Keycode key);
        void drawPacman(SDL_Renderer* gRnderer, SDL_Texture* assets); 
        Unit& pacgetter();
        Unit& pacresetter( Unit& p );
        void freezepacman(SDL_Keycode key);
};
