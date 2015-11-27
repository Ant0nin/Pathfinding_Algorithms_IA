#include "Scene.h"
#include "Controller.h"
#include "const.h"
#include "PileNoeud.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h>

#define PRINT_TEXT \
lineIndex++; \
textSurface = TTF_RenderText_Blended_Wrapped(font, text, text_color, consoleWidth); \
TTF_SizeText(font, text, &fontWidth, &fontHeight); \
lineZone.w = fontWidth; \
lineZone.y = lineIndex * lineZone.h; \
this->texture_console = SDL_CreateTextureFromSurface(this->renderer, textSurface); \
SDL_RenderCopy(renderer, texture_console, NULL, &lineZone);

#define CARRIAGE_RETURN \
memcpy_s(text, bufferLength, "", bufferLength); \
PRINT_TEXT

#define FORMAT_TIME \
_itoa_s(info->duration, text, 10); \
strcat_s(text, " ms"); \
textSurface = TTF_RenderText_Blended_Wrapped(font, text, text_color, consoleWidth);

#define TRACE_LINE \
nodePrevPos = nodePrev->getPosition(); \
nodeSuivPos = nodeSuiv->getPosition(); \
printf("%i %i --- %i %i\n", nodePrevPos.x, nodePrevPos.y, nodeSuivPos.x, nodeSuivPos.y); \
SDL_RenderDrawLine(renderer, \
	nodePrevPos.x * tileWidth + tileWidth / 2, \
	nodePrevPos.y * tileHeight + tileHeight / 2, \
	nodeSuivPos.x * tileWidth + tileWidth / 2, \
	nodeSuivPos.y * tileHeight + + tileHeight / 2 \
);

Scene::Scene(Terrain *terrain, Character *character, ControllerSelector *selector)
{
	this->window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	this->terrain = terrain;
	this->character = character;
	this->selector = selector;

	this->font = TTF_OpenFont(FONT_GENERAL, sizeof(FONT_GENERAL));
	this->text_color = TEXT_COLOR_GENERAL;

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

void Scene::prepareMap(int winWidth, int winHeight, int *mapWidth, int *mapHeight, int *tileWidth, int *tileHeight)
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
	*tileWidth = drawZone.w;
	*tileHeight = drawZone.h;

	*mapWidth = drawZone.w * terrain->width;
	*mapHeight = drawZone.h * terrain->height;

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

	// Affichage du personnage
	SDL_Rect decoupage;
	decoupage.x = 0;
	decoupage.y = 0;
	decoupage.w = 128;
	decoupage.h = 128;
	drawZone.x = terrain->startPosition.x * drawZone.w;
	drawZone.y = terrain->startPosition.y * drawZone.h;
	SDL_RenderCopy(renderer, spritesheet_character, &decoupage, &drawZone);

}

void Scene::prepareConsole(int winWidth, int winHeight, int mapWidth, int mapHeight)
{
	SDL_Rect lineZone;
	const int bufferLength = 64;
	char text[bufferLength];
	int fontWidth, fontHeight;
	const int consoleWidth = winWidth - (winWidth - mapWidth);

	fontHeight = TTF_FontHeight(font);

	// TODO : Corriger les dimensions de la console
	if (winWidth <= winHeight) {
		lineZone.x = 0;
		lineZone.y = winHeight - mapHeight;
		lineZone.w = winWidth;
		lineZone.h = winHeight - lineZone.y;
	}
	else {
		lineZone.x = winWidth - mapWidth;
		lineZone.y = 0;
		lineZone.w = consoleWidth;
		lineZone.h = winHeight / fontHeight;
	}

	ControllerInfo *info = selector->getCurrentController()->getInfo();
	SDL_Surface *textSurface = nullptr; // buffer
	int lineIndex = 0;

	memcpy_s(text, bufferLength, info->controllerName, bufferLength);
	PRINT_TEXT
	CARRIAGE_RETURN

	switch (info->state) {

	case IDLE:
		memcpy_s(text, bufferLength, "IDLE", bufferLength);
		PRINT_TEXT
		break;

	case SUCCESS:
		memcpy_s(text, bufferLength, "SUCCESS", bufferLength);
		PRINT_TEXT
		FORMAT_TIME
		PRINT_TEXT
		// TODO : Afficher les chemins et temps d'execution
		break;

	case FAILED:
		memcpy_s(text, bufferLength, "FAILED", bufferLength);
		PRINT_TEXT
		FORMAT_TIME
		PRINT_TEXT
		// TODO : Afficher temps d'execution
		break;

	}
	this->texture_console = SDL_CreateTextureFromSurface(this->renderer, textSurface);
	SDL_RenderCopy(renderer, texture_console, NULL, &lineZone);
}

// TODO : Faire un code un peu plus élégant pour cette fonction
void Scene::preparePathTrace(int winWidth, int winHeight, int tileWidth, int tileHeight)
{
	Controller *controller = selector->getCurrentController();
	ControllerInfo *info = controller->getInfo();

	// Affichage des chemins de parcours dans l'espace de recherche
	SDL_SetRenderDrawColor(renderer, COLOR_CHEMINEMENT, 1);
	if (info->state != ControllerState::IDLE) {

		list<Noeud*> bestWay = info->bestWay;
		list<Noeud*> charted = info->charted;
		int currentIndex = 0;

		Noeud *nodePrev;
		Noeud *nodeSuiv;
		SDL_Point nodePrevPos;
		SDL_Point nodeSuivPos;

		/*while (currentIndex < info->cheminement.size()) {

			nodePrev = *it;

			while (!controller->isStart(nodePrev)) {
				TRACE_LINE
			}

			it = std::next(it);
			currentIndex++;
		}*/

		// Affichage du bon chemin
		SDL_SetRenderDrawColor(renderer, COLOR_ARRIVE, 1);

		list<Noeud*>::iterator it = bestWay.begin();
		while (it != --bestWay.end()) {
			nodePrev = *it;
			it++;
			nodeSuiv = *it;
			TRACE_LINE
		}

		// Affichage du cheminement
		/*list<Noeud*>::iterator it = charted.begin();
		while (it != --charted.end()) {
			nodePrev = *it;
			it++;
			nodeSuiv = *it;
			TRACE_LINE
		}*/

	}
}

void Scene::render()
{
	int winWidth, winHeight, mapWidth, mapHeight, tileWidth, tileHeight;
	SDL_GetWindowSize(window, &winWidth, &winHeight);

	prepareMap(winWidth, winHeight, &mapWidth, &mapHeight, &tileWidth, &tileHeight);
	prepareConsole(winWidth, winHeight, mapWidth, mapHeight);
	preparePathTrace(winWidth, winHeight, tileWidth, tileHeight);

	SDL_RenderPresent(renderer);
}
