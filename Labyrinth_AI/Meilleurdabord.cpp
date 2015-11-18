#include "Meilleurdabord.h"


using namespace std;

Meilleurdabord::Meilleurdabord(Noeud etatinitial, Operateur op) {



	Pile pile = Pile();
	Noeud curNoeud;
	pile.empil(etatinitial);

	while (pile.pileNoeud.size != 0) {

		curNoeud = pile.depil();

		if (curNoeud.isBut()) {
			//return curNoeud;
			break;
		}

		else {
			Pile listEnfant = Pile();
			//4 le nombre d'operateur
			for (int i = 0; i<4; i++) {
				Noeud curNoeudEnfant = curNoeud.sucesseur(op);
				if (curNoeud.valid()) {
					listEnfant.empil(curNoeudEnfant);
				}
			}
			listEnfant.sort();
			pile.join(listEnfant);
		}
	}



	printf(" Le noeud arrivé au but est : %i / %i", curNoeud.x, curNoeud.y);


}


