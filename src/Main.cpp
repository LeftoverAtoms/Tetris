#include <iostream>

#include "Game.h"

int main(int argc, char* args[])
{
	Game* game = new Game("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 384, 704);

	game->Start();

	int frame_delta = 0;
	int frame_target = 1000 / 15;
	int last_tick = 0;

	while (game->IsActive)
	{
		int tick = SDL_GetTicks64();
		frame_delta = tick - last_tick;

		game->Events();

		if (frame_delta >= frame_target)
		{
			last_tick = tick;

			game->Update();
			game->Render();
		}
	}

	game->Quit();

	return 0;
}