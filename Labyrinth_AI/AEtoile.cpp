#include "AEtoile.h"

using namespace std;

AEtoile::AEtoile(Noeud* etatinitial, Direction op) {



	Pile pile = Pile(),noeudInexplo = Pile(), noeudExplo = Pile();
	Noeud* curNoeud;
	pile.empil(etatinitial);
	noeudInexplo.empil(etatinitial);
	

	while (pile.pileNoeud.size != 0) {
		curNoeud = pile.depil();
		noeudExplo.depil();
		noeudInexplo.empil(curNoeud);


		/*if (curNoeud->isBut()) {
			//return curNoeud;
			break;
		}
		else {
			Pile listEnfant = Pile();
			//4 le nombre d'operateur
			for (int i = 0; i<4; i++) {
				Noeud* curNoeudEnfant = curNoeud->sucesseur(op);
				//TODO : Son test chelou AEtoile par rapport au cout et il ne teste jamais si c'est un mur
				if ((noeudInexplo.isIn(curNoeudEnfant) && noeudExplo.isIn(curNoeud))) {
					curNoeudEnfant.g = curNoeud.g + cout(curNoeud, curNoeudEnfant);
					//TODO : On peut calculer ca dans le noeud directement
					curNoeudEnfant.f = curNoeudEnfant.g + curNoeudEnfant.h;
					//Deja fait curNoeudEnfant.popa(curNoeud);
					listEnfant.empil(curNoeudEnfant);
				}
				noeudInexplo.empil(curNoeudEnfant);
				//On enleve l'enfant des explorés

			}
			//listEnfant.sort();
			//pile.join(listEnfant);
		}*/
	}



	printf(" Le noeud arrivé au but est : %i / %i", curNoeud->pos.x, curNoeud->pos.y);


}


