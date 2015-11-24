#include "AEtoile.h"

using namespace std;

AEtoile::AEtoile(Noeud * etatInitial, Terrain * terrain, std::list<Direction>* op)
	: Controller("A Star", etatInitial, terrain, op)
{
}

void AEtoile::execute() {

	info.state = ControllerState::SUCCESS;

	/*Pile pile = Pile(), noeudInexplo = Pile(), noeudExplo = Pile();
	Noeud* curNoeud;
	pile.empil(etatinitial);
	noeudInexplo.empil(etatinitial);


	while (pile.pileNoeud.size != 0) {
		curNoeud = pile.depil();
		noeudExplo.depil();
		noeudInexplo.empil(curNoeud);


		if (curNoeud->isValid(ter)) {
			//return curNoeud;
			break;
		}
		else {
			Pile listEnfant = Pile();
			//4 le nombre d'operateur
			std::list<Direction>::iterator it = op->begin();
			for (int i = 0; i<op->size(); i++) {
				Noeud* curNoeudEnfant = curNoeud->successeur(*it);

				//TODO : Son test chelou AEtoile par rapport au cout et il ne teste jamais si c'est un mur
				if ((noeudInexplo.isIn(curNoeudEnfant) && noeudExplo.isIn(curNoeud))) {
					//Remplacer cout(curNoeud, curNoeudEnfant) par 1
					curNoeudEnfant->g = curNoeud->g + 1;
					//TODO : On peut calculer ca dans le noeud directement
					curNoeudEnfant->f = curNoeudEnfant->g + curNoeudEnfant->h;
					//Deja fait a la creation du noeud enfant curNoeudEnfant.popa(curNoeud);
					listEnfant.empil(curNoeudEnfant);
				}
				noeudInexplo.empil(curNoeudEnfant);
				//On enleve l'enfant des explorés

			}
			//listEnfant.sort();
			//pile.join(listEnfant);
		}
	}*/

}




