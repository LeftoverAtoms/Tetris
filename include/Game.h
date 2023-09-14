#pragma once

#include "Entity.h"
#include "Shape.h"
#include <vector>

class Game
{
private:
	void CreateGrid(const char* filePath, int scale);
	void ConfirmQuit();

public:
	static std::vector<Entity*> Entities;
	static Entity* Grid[10][20];

	static SDL_Renderer* Renderer;
	static SDL_Window* Window;

	const Shape O =
	{
		.Data =
		{
			{ 1, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		.Tint = { 255, 255, 255, 255 }
	};
	const Shape I =
	{
		.Data =
		{
			{ 1, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 1, 0, 0, 0 }
		},
		.Tint = { 255, 255, 255, 255 }
	};
	const Shape S =
	{
		.Data =
		{
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		.Tint = { 255, 255, 255, 255 }
	};
	const Shape Z =
	{
		.Data =
		{
			{ 1, 0, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		.Tint = { 255, 255, 255, 255 }
	};
	const Shape L =
	{
		.Data =
		{
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		.Tint = { 255, 255, 255, 255 }
	};
	const Shape J =
	{
		.Data =
		{
			{ 1, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		.Tint = { 255, 255, 255, 255 }
	};
	const Shape T =
	{
		.Data =
		{
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		.Tint = { 255, 255, 255, 255 }
	};

	bool IsActive;

	Game(const char* title, int x, int y, int w, int h);
	~Game();

	void Start();
	void Events();
	void Update();
	void Render();
	void Quit();
};