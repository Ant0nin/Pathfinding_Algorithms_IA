#pragma once
#include "Controller.h"
#include "Character.h"
#include "Terrain.h"

class CoutsUniform :
	public Controller
{
protected: 
	int profondeur;
public:
	CoutsUniform(Noeud * etatInitial, Terrain * terrain, std::list<Direction> * op);
	virtual void heuristique(Noeud *) override;
};

