#include <iostream>

#include "Block.h"
#include "Game.h"

int main(int argc, char* args[])
{
	Game* game = new Game();

	game->Init("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 384, 704);

	(new Block())->SetTexture("res/blue_frog.png");

	int lastTick = 0;
	int delta = 0;

	while (game->IsActive)
	{
		int curTick = SDL_GetTicks();
		delta = curTick - lastTick;

		game->Events();

		if (delta > 16)
		{
			lastTick = curTick;

			game->Update();
			game->Render();
		}
	}

	game->Quit();

	return 0;
}