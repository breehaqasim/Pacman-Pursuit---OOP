#include<SDL.h>
#include <SDL_mixer.h>
#include <vector>
#include "pacman.hpp"
#include "pink.hpp"
#include "red.hpp"
#include "purple.hpp"
#include "orange.hpp"
#include "blue.hpp"
#include "death.hpp"
#include "dot.hpp"
#include "game.hpp"
#pragma once

class Level1
{
    private:
        Unit arrow= {{281,401,324,236}, {1000, 100, 120, 120}};
        Death deathCounter;
    public:
        void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets,std::vector<Enemy*>& enemies, Pacman& pac,Dot& dot, Death& death);
};
