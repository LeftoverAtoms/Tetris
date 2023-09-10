#include <vector>
#include "Game.h"

Game::Game()
{
	IsActive = false;
	Renderer = NULL;
	Window = NULL;
}
Game::~Game()
{
}

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
			Game::ConfirmQuit();
			break;
		}
	}
}
void Game::Update()
{
	for (int i = 0; i < Game::Entities.size(); i++)
	{
		Game::Entities[i]->Update();
	}
}
void Game::Render()
{
	SDL_RenderClear(Renderer);

	for (int i = 0; i < Game::Entities.size(); i++)
	{
		Game::Entities[i]->Render();
	}

	SDL_RenderPresent(Renderer);
}
void Game::Quit()
{
	for (int i = 0; i < Game::Entities.size(); i++)
	{
		delete(Game::Entities[i]);
	}

	Game::Entities.clear();

	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();

	delete(this);
}

void Game::ConfirmQuit()
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
		Game::IsActive = false;
	}
}