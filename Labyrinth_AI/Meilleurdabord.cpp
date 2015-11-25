#include "Meilleurdabord.h"
#include "Controller.h"
#include <string>

using namespace std;

//TODO : finir l'algo et afficher le chemin

Meilleurdabord::Meilleurdabord(Noeud* etatInitial, Terrain *ter, std::list<Direction> *op)
	: Controller("Best First", etatInitial, ter, op)
{
}

void Meilleurdabord::execute()
{
	//terrain = ter;


	
	PileNoeud pile = PileNoeud();
	Noeud* curNoeud;
	pile.empil(etatInitial);
	PileNoeud solution = PileNoeud();

	while (pile.pileNoeud.size() != 0) {
		curNoeud = pile.depil();
		solution.empil(curNoeud);

		if (curNoeud->isBut(this->terrain)) {
			//return curNoeud;
			break;
		}
		else {
			PileNoeud listEnfant = PileNoeud();
			//4 le nombre d'operateur
			std::list<Direction>::iterator it = op->begin();
			for (int i = 0; i<op->size(); i++) {
				Noeud* curNoeudEnfant = curNoeud->successeur(*it);
				if (curNoeudEnfant->isValid(this->terrain)) {
					listEnfant.empil(curNoeudEnfant);
				}
			}
			listEnfant.sort();
			pile.join(listEnfant);
		}
	}
	//	printf(" Le noeud arrivé au but est : %i / %i", curNoeud->getPosition.x, curNoeud->getPosition.y);
}





