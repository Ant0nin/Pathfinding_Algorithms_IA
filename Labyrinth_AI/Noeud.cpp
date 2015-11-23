#include "Noeud.h"
#include <cmath>

Noeud::Noeud(SDL_Point pos, Noeud* pere)
{
	this->pos = pos;
	parent = pere;
	heur = calcHeur();
}

Noeud* Noeud::successeur(Direction op)
{
	SDL_Point newPos = pos;

	switch (op)
	{
	case HAUT:
		newPos.y--;
		break;
	case BAS:
		newPos.y++;
		break;
	case GAUCHE:
		newPos.x--;
		break;
	case DROITE:
		newPos.x++;
		break;
	}

	return new Noeud(newPos, this);
}

bool Noeud::isValid(Terrain * terrain)
{
	Tile target = terrain->tiles[pos.x + terrain->width * pos.y];
	return (target != Tile::WALL);
}

bool Noeud::isBut(Terrain * terrain)
{
	Tile target = terrain->tiles[pos.x + terrain->width * pos.y];
	return (target == Tile::EXIT);
}

bool Noeud::isStart()
{
	return (getParent() == nullptr);
}

Noeud* Noeud::getParent()
{
	return parent;
}

SDL_Point Noeud::getPosition()
{
	return pos;
}

int Noeud::calcHeur()
{
	float ret = sqrt(pow(pos.x - 1,2) + pow(pos.y - 1,2));
	return ret;
}
