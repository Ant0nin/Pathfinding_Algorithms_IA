#include "CoutsUniform.h"
#include "PileNoeud.h"


CoutsUniform::CoutsUniform(Noeud * etatInitial, Terrain * terrain, std::list<Direction> * op)
	: Controller("Uniform-cost search", etatInitial, terrain, op)
{
}

void CoutsUniform::execute()
{
	PileNoeud pile = PileNoeud();
	Noeud* curNoeud;
	pile.empil(etatInitial);
	PileNoeud solution = PileNoeud();

	while (pile.size() != 0) {
		curNoeud = pile.depil();
		printf("Le noeud est : %i / %i \n", curNoeud->getPosition());
		solution.empil(curNoeud);

		if (isBut(curNoeud)) {
			//return curNoeud;
			break;
		}
		else {
			PileNoeud listEnfant = PileNoeud();
			//4 le nombre d'operateur
			std::list<Direction>::iterator it = op->begin();
			for (; it != op->end(); it++) {
				Noeud* curNoeudEnfant = curNoeud->successeur(*it);
				printf("		Enfant : %i / %i", curNoeudEnfant->getPosition(), it);
				printf("	Prejent : %d \n", pile.isIn(curNoeudEnfant));
				if (this->isValid(curNoeudEnfant) && !pile.isIn(curNoeudEnfant)) {
					//listEnfant.empil(curNoeudEnfant);
					pile.empil(curNoeudEnfant);
				}
			}
			//listEnfant.sort();
			//pile.join(listEnfant);
		}


	}
}

