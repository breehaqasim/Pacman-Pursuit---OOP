#include "unit.hpp"
#pragma once
#include <SDL.h>

//Pacman inherits from Unit

class Pacman : public Unit 
{
    public:
        void movePacman(SDL_Keycode key);
        void drawPacman(SDL_Renderer* gRnderer, SDL_Texture* assets);
};
