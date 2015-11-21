#include "Scene.h"
#include "Controller.h"
#include "const.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h>
#include <string>

Scene::Scene(Terrain *terrain, Character *character, ControllerSelector *selector)
{
	this->window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	this->terrain = terrain;
	this->character = character;
	this->selector = selector;
	this->font = TTF_OpenFont(FONT_GENERAL, sizeof(FONT_GENERAL));

	initTextures();
}

Scene::~Scene()
{
	TTF_CloseFont(font);
}

void Scene::initTextures()
{
	SDL_Surface *buffer;
	
	buffer = IMG_Load(TEXTURE_BACKGROUND);
	this->texture_bg = SDL_CreateTextureFromSurface(this->renderer, buffer);

	buffer = IMG_Load(TEXTURE_FLOOR_UNIT);
	this->texture_floor_unit = SDL_CreateTextureFromSurface(this->renderer, buffer);

	buffer = IMG_Load(TEXTURE_EXIT_UNIT);
	this->texture_exit_unit = SDL_CreateTextureFromSurface(this->renderer, buffer);

	buffer = IMG_Load(SPRITESHEET_CHARACTER);
	this->spritesheet_character = SDL_CreateTextureFromSurface(this->renderer, buffer);

	SDL_free(buffer);
}

void Scene::prepareMap(int winWidth, int winHeight)
{
	SDL_Rect drawZone;

	drawZone.x = 0;
	drawZone.y = 0;
	drawZone.w = winWidth;
	drawZone.h = winHeight;
	SDL_RenderCopy(renderer, texture_bg, NULL, &drawZone);

	if (winWidth <= winHeight)
		drawZone.w = (winWidth - winWidth % terrain->width) / terrain->width;
	else
		drawZone.w = (winHeight - winHeight % terrain->height) / terrain->height;
	drawZone.h = drawZone.w;

	// Affichage du terrain
	for (int i = 0; i < terrain->height; i++) {

		drawZone.y = i * drawZone.h;

		for (int j = 0; j < terrain->width; j++) {

			drawZone.x = j * drawZone.w;

			Tile tile = terrain->tiles[i * terrain->width + j];

			switch (tile) {
			case FLOOR:
				SDL_RenderCopy(renderer, texture_floor_unit, NULL, &drawZone);
				break;

			case EXIT:
				SDL_RenderCopy(renderer, texture_exit_unit, NULL, &drawZone);
				break;
			}
		}
	}
}

void Scene::prepareConsole(int winWidth, int winHeight)
{
	SDL_Rect consoleZone;
	
	if (winWidth <= winHeight) {
		consoleZone.x = (winWidth - winWidth % terrain->width) / terrain->width;
		consoleZone.w = winWidth - consoleZone.x;
		consoleZone.y = 0;
	}
	else {
		consoleZone.y = (winHeight - winHeight % terrain->height) / terrain->height;
		consoleZone.w = winHeight - consoleZone.y;
		consoleZone.x = 0;
	}
	consoleZone.h = consoleZone.w;

	ControllerInfo *info = selector->getCurrentController()->getInfo();
	SDL_Surface *textSurface = nullptr; // TODO : gérer l'erreur
	SDL_Color color = { 0,0,0 };

	switch (info->state) {

	case IDLE:
		textSurface = TTF_RenderText_Solid(font, info->controllerName, color);
		break;

	case SUCCESS:
		textSurface = TTF_RenderText_Solid(font, info->controllerName, color);
		// TODO : Afficher les chemins et temps d'execution
		break;

	case FAILED:
		textSurface = TTF_RenderText_Solid(font, info->controllerName, color);
		// TODO : Afficher temps d'execution
		break;

	}
	this->texture_console = SDL_CreateTextureFromSurface(this->renderer, textSurface);
	SDL_RenderCopy(renderer, texture_console, NULL, &consoleZone);
}

void Scene::preparePathTrace(int winWidth, int winHeight)
{
	// TODO
}

void Scene::render()
{
	int winWidth, winHeight;
	SDL_GetWindowSize(window, &winWidth, &winHeight);

	prepareMap(winWidth, winHeight);
	prepareConsole(winWidth, winHeight);
	preparePathTrace(winWidth, winHeight);

	SDL_RenderPresent(renderer);
}
