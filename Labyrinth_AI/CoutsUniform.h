#pragma once
#include "Controller.h"
#include "Character.h"
#include "Terrain.h"

class CoutsUniform :
	public Controller
{
public:
	CoutsUniform(SDL_Point * characterPosition, Terrain * terrain, std::list<Direction> * op);
	virtual void execute() override;
};

