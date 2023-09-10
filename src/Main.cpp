#include "Game.h"
#include <SDL.h>

int main(int argc, char* args[])
{
	Game* game = new Game();

	game->Init("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360);

	Entity* ent = new Entity();

	while (game->IsActive)
	{
		game->Events();
		game->Update();
		game->Render();
	}

	game->Quit();

	return 0;
}