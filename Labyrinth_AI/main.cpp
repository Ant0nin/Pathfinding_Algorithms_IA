#include <SDL2\SDL.h>

#include "TerrainFactory.h"
#include "Character.h"
#include "Scene.h"
#include "InputListener.h"

#include "const.h"
#include <list>

#include "Meilleurdabord.h"
#include "AEtoile.h"
#include "CoutsUniform.h"

#undef main

int main(int argc, int *argv) {

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
	controllers.push_back(new Meilleurdabord(character.position, terrain, op));
	controllers.push_back(new AEtoile(character.position, terrain, op));
	controllers.push_back(new CoutsUniform(character.position, terrain, op));

	ControlPanel *controlPanel = new ControlPanel(controllers);

	Scene *scene = new Scene(terrain, &character, controlPanel);
	scene->render();

	InputListener *listener = new InputListener(controlPanel, scene);
	listener->run();

	SDL_Delay(10000); // TODO : retirer

	SDL_Quit();
	return EXIT_SUCCESS;
}