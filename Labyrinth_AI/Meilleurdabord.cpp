#include "Meilleurdabord.h"
#include "Controller.h"
#include <string>
#include <list>

using namespace std;

//TODO : finir l'algo et afficher le chemin

Meilleurdabord::Meilleurdabord(Noeud* etatInitial, Terrain *ter, std::list<Direction> *op)
	: Controller("Best First", etatInitial, ter, op)
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

void Meilleurdabord::heuristique(Noeud* n) {
	SDL_Point pos;
	float distance = 0;
	std::list<SDL_Point>::iterator it;
	it = listExit.begin();
	pos = *it;
	distance = sqrt(pow(n->getPosition().x - pos.x, 2) + pow(n->getPosition().y - pos.y, 2));
	it++;
	while (it != listExit.end()) {
		float temp = sqrt(pow(n->getPosition().x - pos.x, 2) + pow(n->getPosition().y - pos.y, 2));
		if (temp < distance)
			distance = temp;
		it++;
	}
	n->heur = -distance;
}