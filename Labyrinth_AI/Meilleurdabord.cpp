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
	PileNoeud aExplo = PileNoeud(),dejaExplo= PileNoeud();
	Noeud* curNoeud = NULL;
	aExplo.empil(etatInitial);
	int nbNoeudExplo = 0;

	while (aExplo.size() != 0) {
		curNoeud = aExplo.depil();
		dejaExplo.empil(curNoeud);
		nbNoeudExplo++;
		printf("Le noeud est : %i / %i \n",curNoeud->getPosition());
	
		if (isBut(curNoeud)) {
			//return curNoeud;
			break;
		}
		else {
			//4 le nombre d'operateur
			std::list<Direction>::iterator it = op->begin();
			for (;it!=op->end(); it++) {
				Noeud* curNoeudEnfant = curNoeud->successeur(*it);
				//printf("		Enfant : %i / %i", curNoeudEnfant->getPosition(),it);
				//printf("	Prejent : %d \n", dejaExplo.isIn(curNoeudEnfant));
				if (isValid(curNoeudEnfant) && (!dejaExplo.isIn(curNoeudEnfant) && !aExplo.isIn(curNoeudEnfant))) {
					aExplo.empil(curNoeudEnfant);
				}
			}
			//listEnfant.sort();
			//pile.join(listEnfant);
		}
	}

	info.arrive = curNoeud;

	while (!isStart(curNoeud)) {
		info.cout++;
		curNoeud = curNoeud->getParent();
	}

	printf("La sortie est : %i / %i : %i/%i exploré\n", curNoeud->getPosition(),info.cout,nbNoeudExplo);
}