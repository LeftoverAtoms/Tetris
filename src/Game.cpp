#include <SDL.h>

#include "Game.h"

Game::Game() {}
Game::~Game() {}

void Game::Init(const char* title, int x, int y, int w, int h)
{
	SDL_InitSubSystem(SDL_INIT_EVERYTHING);

	Window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);

	Renderer = SDL_CreateRenderer(Window, -1, 0);

	Game::IsActive = true;
}

void Game::Events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT: {
			Game::Quit();
			break;
		}
	}
}
void Game::Update()
{

}
void Game::Render()
{
	SDL_RenderClear(Renderer);

	// TODO:
	// Render entities using a collection

	SDL_RenderPresent(Renderer);
}
void Game::Clean()
{
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}

void Game::Quit()
{
	const SDL_MessageBoxButtonData buttons[] =
	{
		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "No" },
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "Yes" },
	};

	const SDL_MessageBoxData data =
	{
		SDL_MESSAGEBOX_INFORMATION,
		NULL,
		"Are you sure you want to quit?",
		"Are you sure you want to quit?",
		2,
		buttons,
		NULL
	};

	int buttonid;
	SDL_ShowMessageBox(&data, &buttonid);

	if (buttonid == 0)
	{
		SDL_Log("Program quit after %i ticks", SDL_GetTicks());

		Game::IsActive = false;
	}
}

bool Game::Active()
{
	return Game::IsActive;
}