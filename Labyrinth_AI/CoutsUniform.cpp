#include "CoutsUniform.h"



CoutsUniform::CoutsUniform(SDL_Point * characterPosition, Terrain * terrain, std::list<Direction> * op)
	: Controller("Uniform-cost search", characterPosition, terrain, op)
{
}

void CoutsUniform::execute()
{
}

