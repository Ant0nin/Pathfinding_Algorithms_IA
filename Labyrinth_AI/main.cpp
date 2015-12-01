#include <SDL2\SDL.h>
#include <SDL2\SDL_ttf.h>
#include <SDL2\SDL_image.h>

#include "TerrainFactory.h"
#include "Character.h"
#include "Scene.h"
#include "InputListener.h"
#include "Controller.h"
#include "ControllerSelector.h"
#include "Noeud.h"

#include "const.h"
#include <list>

#include "Meilleurdabord.h"
#include "PrioriteProche.h"
#include "AEtoile.h"
#include "CoutsUniform.h"

#undef main

int main(int argc, int *argv) {

	// TODO : Afficher le ratio nb coups / chemin plus court
	// TODO : Avoir la possibilité de changer de niveau pdt l'exécution
	// TODO : Afficher le texte dans une pseudo-console

	TTF_Init();
	SDL_Init(SDL_INIT_VIDEO);

	TerrainFactory *factory = new TerrainFactory(LEVEL_NUMBER);
	Terrain *terrain = &factory->createTerrain();

	Character character;
	character.position = &terrain->startPosition;

	// Liste des opérateurs
	std::list<Direction> op;
	op.push_back(Direction::HAUT);
	op.push_back(Direction::BAS);
	op.push_back(Direction::GAUCHE);
	op.push_back(Direction::DROITE);

	// Liste des controllers (algorithmes IA)
	std::list<Controller*> controllers;
	Noeud* noeudInit = new Noeud(*character.position);
	controllers.push_back(new Meilleurdabord(noeudInit, terrain, &op));
	controllers.push_back(new AEtoile(noeudInit, terrain, &op));
	controllers.push_back(new CoutsUniform(noeudInit, terrain, &op));
	controllers.push_back(new PrioriteProche(noeudInit, terrain, &op));
	//TODO: Antonin ton fort
	ControllerSelector *selector = new ControllerSelector(controllers);

	Scene *scene = new Scene(terrain, &character, selector);
	InputListener *listener = new InputListener(scene, selector);

	scene->render();
	listener->run();

	SDL_Quit();
	TTF_Quit();

	// TODO : free resources

	return EXIT_SUCCESS;
}