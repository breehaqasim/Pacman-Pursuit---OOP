#include "unit.hpp"
#pragma once

bool Unit::checkCollision(const Unit& other) const 
{
        return SDL_HasIntersection(&this->moverRect, &other.moverRect);
}
