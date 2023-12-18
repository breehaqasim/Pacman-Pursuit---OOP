#include "unit.hpp"
#pragma once
#include <SDL.h>
#include <vector>
#include "game.hpp"
#include "pacman.hpp"
#include <SDL_ttf.h>

class Dot 
{
    private:
        bool flag=false;
        std::vector<Unit> dots;
        int score = 0;
        int checkval=0;
    public:
        Dot();
        void initializeDots();
        int drawDot(SDL_Renderer* gRnderer, SDL_Texture* assets, Pacman& pac);
        int scoregetter();
        int checkvalgetter();
};
