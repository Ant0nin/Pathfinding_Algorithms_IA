#include "AEtoile.h"

using namespace std;

AEtoile::AEtoile(Noeud * etatInitial, Terrain * ter, std::list<Direction>* op)
	: Controller("A Star", etatInitial, ter, op)
{

	listExit = list<SDL_Point>();
	int w = ter->width;
	int h = ter->height;

	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {

			if (ter->tiles[j * w + i] == Tile::EXIT) {

				SDL_Point p;
				p.x = i;
				p.y = j;
				listExit.push_front(p);
			}
		}
	}
}

void AEtoile::heuristique(Noeud* n) {
	
	
	if (isStart(n))
		n->g = 0;
	else {
		n->g= n->getParent()->g - 1;
	}
	
	SDL_Point pos;
	float distExit = 0;
	std::list<SDL_Point>::iterator it;
	it = listExit.begin();
	pos = *it;
	distExit= sqrt(pow(n->getPosition().x - pos.x, 2) + pow(n->getPosition().y - pos.y, 2));
	it++;
	while (it != listExit.end()) {
		float temp = sqrt(pow(n->getPosition().x - pos.x, 2) + pow(n->getPosition().y - pos.y, 2));
		if (temp < distExit)
			distExit = temp;
		it++;
	}
	n->heur = -( distExit+ 5*n->g );
}

