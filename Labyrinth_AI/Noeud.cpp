#include "Noeud.h"


Noeud* popa;

Noeud::Noeud(SDL_Point pos,Noeud* pere)
{
	this->pos = pos;
	popa = pere;
	heur = calcHeur();

}

Noeud* Noeud::sucesseur(Direction op)
{
	int newX = pos.x;
	int newY = pos.y;
	switch (op)
	{
	case HAUT:
		newY--;
		break;
	case BAS:
		newY++;
		break;
	case GAUCHE:
		newX--;
		break;
	case DROITE:
		newX++;
		break;
	}
	return &Noeud(newX,newY,this);
}

Noeud* Noeud::getPopa()
{
	return popa;
}

int Noeud::calcHeur()
{
	float ret = sqrt(pow(pos.x - 1,2) + pow(pos.y - 1,2));
	return ret;
}
