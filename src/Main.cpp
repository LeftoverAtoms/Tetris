#include <SDL.h>

#include "Game.h"

int main(int argc, char* args[])
{
	Game* game = new Game();

	game->Init("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360);

	while (game->Active())
	{
		game->Events();
		game->Update();
		game->Render();
	}

	game->Clean();

	return 0;
}