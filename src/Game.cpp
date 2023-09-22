#include "Game.h"
#include "Input.h"
#include <iostream>
#include <Player.h>

std::vector<Entity*> Game::Entities;

SDL_Renderer* Game::Renderer = nullptr;
SDL_Window* Game::Window = nullptr;

Game::Game(const char* title, int x, int y, int w, int h)
{
	SDL_InitSubSystem(SDL_INIT_EVERYTHING);

	Window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
	if (Window == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	Renderer = SDL_CreateRenderer(Window, -1, 0);
	if (Renderer == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	IsActive = true;
}
Game::~Game() {}

void Game::Start()
{
	Entity* background = new Entity();
	background->SetTexture("res/grid.png");
	background->SetPosition(32, 32);
	background->SetScale(320, 640);

	Player* player = new Player();
	player->ParseBlock(J);

	for (int i = 0; i < Entities.size(); i++)
	{
		Entities[i]->Start();
	}
}
void Game::Events()
{
	SDL_Event event;

	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_KEYDOWN:
		{
			Input::Key = event.key;
			break;
		}
		case SDL_KEYUP:
		{
			Input::Key = event.key;
			break;
		}
		case SDL_QUIT: {
			ConfirmQuit();
			break;
		}
	}
}
void Game::Update()
{
	for (int i = 0; i < Entities.size(); i++)
	{
		Entities[i]->Update();
	}
}
void Game::Render()
{
	if (SDL_RenderClear(Renderer) != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	for (int i = 0; i < Entities.size(); i++)
	{
		Entity* ent = Entities[i];

		if (ent->Active)
		{
			ent->Render();
		}
	}

	SDL_RenderPresent(Renderer);
}
void Game::Quit()
{
	//for (int i = 0; i < Entities.size(); i++)
	//{
		//delete(Entities[i]);
	//}
	Entities.clear();

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
		IsActive = false;
	}
}