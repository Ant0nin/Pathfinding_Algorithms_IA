#include "Meilleurdabord.h"
#include "Controller.h"
#include <string>

using namespace std;

Meilleurdabord::Meilleurdabord(Noeud* characterPosition, Terrain *ter, std::list<Direction> *op){
	//terrain = ter;
	Pile pile = Pile();
	Noeud* curNoeud;
	pile.empil(characterPosition);
	Pile solution = Pile();

	while (pile.pileNoeud.size() != 0) {
		curNoeud = pile.depil();
		solution.empil(curNoeud);

		if (curNoeud->isBut(ter)) {
			//return curNoeud;
			break;
		}
		else {
			Pile listEnfant = Pile();
			//4 le nombre d'operateur
			std::list<Direction>::iterator it = op->begin();
			for (int i = 0; i<op->size(); i++) {
				Noeud* curNoeudEnfant = curNoeud->successeur(*it);
				if (curNoeudEnfant->isValid(ter)) {
					listEnfant.empil(curNoeudEnfant);
				}
			}
			listEnfant.sort();
			pile.join(listEnfant);
		}
	}
//	printf(" Le noeud arrivé au but est : %i / %i", curNoeud->getPosition.x, curNoeud->getPosition.y);
}

/*
Meilleurdabord::Meilleurdabord(SDL_Point * characterPosition, Terrain * terrain, std::list<Direction> * op)
	: Controller("Best first", characterPosition, terrain, op)
{
}*/

bool Meilleurdabord::isValid(SDL_Point* pos)
{
	/*bool ret = true;
	//TODO : Antonin verifie si la condition est bonne
	if (*terrain->tiles+ (sizeof(Tile)*pos->x) + (terrain->width*pos->y) == WALL) ret = false;
	return ret;*/
	return true;
}

bool Meilleurdabord::isBut(SDL_Point* pos)
{
	/*bool ret = false;
	//TODO : Antonin verifie si la condition est bonne
	if (*terrain->tiles + (sizeof(Tile)*pos->x) + (terrain->width*pos->y) == EXIT) ret = false;
	return ret;*/

	return true;
}

void Meilleurdabord::execute()
{
	// TODO
}





