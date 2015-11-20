#include "Meilleurdabord.h"


using namespace std;

Meilleurdabord::Meilleurdabord(Noeud* etatinitial, Direction *op, Terrain * ter) {
	terrain = ter;
	Pile pile = Pile();
	Noeud* curNoeud;
	pile.empil(etatinitial);
	Pile solution = Pile();

	while (pile.pileNoeud.size != 0) {
		curNoeud = pile.depil();
		solution.empil(curNoeud);

		if (isBut(&curNoeud->pos)) {
			//return curNoeud;
			break;
		}
		else {
			Pile listEnfant = Pile();
			//4 le nombre d'operateur
			for (int i = 0; i<4; i++) {
				Noeud* curNoeudEnfant = curNoeud->sucesseur(*op);
				if (isValid(&curNoeud->pos)) {
					listEnfant.empil(curNoeudEnfant);
				}
			}
			listEnfant.sort();
			pile.join(listEnfant);
		}
	}
	printf(" Le noeud arrivé au but est : %i / %i", curNoeud->pos.x, curNoeud->pos.y);
}

bool Meilleurdabord::isValid(SDL_Point* pos)
{
	bool ret = true;
	//TODO : Antonin verifie si la condition est bonne
	if (*terrain->tiles+ (sizeof(Tile)*pos->x) + (terrain->width*pos->y) == WALL) ret = false;
	return ret;
}

bool Meilleurdabord::isBut(SDL_Point* pos)
{
	bool ret = false;
	//TODO : Antonin verifie si la condition est bonne
	if (*terrain->tiles + (sizeof(Tile)*pos->x) + (terrain->width*pos->y) == EXIT) ret = false;
	return ret;
}





