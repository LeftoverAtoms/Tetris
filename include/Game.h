#pragma once

#include "Block.h"
#include "Entity.h"
#include <vector>

class Game
{
private:
	void ParseBlock(Block block);
	void ConfirmQuit();

public:
	const Block I = { .Shape = 0b1000100010001000, .Color = {  0,  100, 100, 255 } };
	const Block O = { .Shape = 0b1100110000000000, .Color = { 100, 100,   0, 255 } };
	const Block T = { .Shape = 0b0100111000000000, .Color = { 64,    0, 100, 255 } };
	const Block S = { .Shape = 0b0110110000000000, .Color = {  0,  100,   0, 255 } };
	const Block Z = { .Shape = 0b1100011000000000, .Color = { 100,   0,   0, 255 } };
	const Block J = { .Shape = 0b0100010011000000, .Color = {  0,    0, 100, 255 } };
	const Block L = { .Shape = 0b1000100011000000, .Color = { 100,  64,   0, 255 } };

	static std::vector<Entity*> Entities;
	static Entity* Grid[10][20];

	static SDL_Renderer* Renderer;
	static SDL_Window* Window;

	bool IsActive;

	Game(const char* title, int x, int y, int w, int h);
	~Game();

	void Start();
	void Events();
	void Update();
	void Render();
	void Quit();
};