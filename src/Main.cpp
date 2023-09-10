#include "Block.h"
#include "Game.h"

int main(int argc, char* args[])
{
	Game* game = new Game();

	game->Init("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360);

	(new Block())->SetSprite("res/blue_frog.png");

	while (game->IsActive)
	{
		game->Events();
		game->Update();
		game->Render();
	}

	game->Quit();

	return 0;
}