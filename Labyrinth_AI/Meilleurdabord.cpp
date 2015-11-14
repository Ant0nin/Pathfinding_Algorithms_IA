#include "Meilleurdabord.h"
#include <SDL2\SDL.h>
#include <string>

using namespace std;

Meilleurdabord::Meilleurdabord(Noeud etatinitial, Operateur op) {



	Pile pile = new Pile();

	pile.insert(etatinitial, etatinitial.heurist);

	while (pile.lentgh != 0) {

		curNoeud = pile.pick();

		if (curNoeud.sucesseur == 0) {//test but ?
			return curNoeud;
		}

		else {
			listEnfant = [op.lentgh];
			for (var i = 0; i<op.lentgh; i++) {
				curNoeudEnfant = sucesseur(curNoeud, op[i]);
				if (valide(curNoeudEnfant)) {
					//pile.insert(curNoeudEnfant,heurist(curNoeudEnfant));
					listEnfant.push(curNoeudEnfant);
				}
			}
			listEnfant.sort(triPile);
			pile = pile.join(listEnfant);
		}
	}


}


