#pragma once

#include "Block.h"
#include "Entity.h"
#include <vector>

class Game
{
private:
	void ConfirmQuit();

public:
	const Block I_0 = { .Shape = 0b0100010001000100, .Color = {  0, 100, 100, 255 } };
	const Block I_90 = { .Shape = 0b0000111100000000, .Color = {  0, 100, 100, 255 } };
	const Block I_180 = { .Shape = 0b0010001000100010, .Color = {  0, 100, 100, 255 } };
	const Block I_270 = { .Shape = 0b0000000011110000, .Color = {  0, 100, 100, 255 } };

	const Block O_0 = { .Shape = 0b1100110000000000, .Color = { 100, 100, 0, 255 } };
	const Block O_90 = { .Shape = 0b1100110000000000, .Color = { 100, 100, 0, 255 } };
	const Block O_180 = { .Shape = 0b1100110000000000, .Color = { 100, 100, 0, 255 } };
	const Block O_270 = { .Shape = 0b1100110000000000, .Color = { 100, 100, 0, 255 } };

	const Block T_0 = { .Shape = 0b0100111000000000, .Color = { 64, 0, 100, 255 } };
	const Block T_90 = { .Shape = 0b0010001100100000, .Color = { 64, 0, 100, 255 } };
	const Block T_180 = { .Shape = 0b0000000011100100, .Color = { 64, 0, 100, 255 } };
	const Block T_270 = { .Shape = 0b0100110001000000, .Color = { 64, 0, 100, 255 } };

	const Block S_0 = { .Shape = 0b0110110000000000, .Color = {  0,100, 0, 255 } };
	const Block S_90 = { .Shape = 0b0010001100010000, .Color = {  0,100, 0, 255 } };
	const Block S_180 = { .Shape = 0b0000000011000110, .Color = {  0,100, 0, 255 } };
	const Block S_270 = { .Shape = 0b0000100011000100, .Color = {  0,100, 0, 255 } };

	const Block Z_0 = { .Shape = 0b1100011000000000, .Color = { 100, 0, 0, 255 } };
	const Block Z_90 = { .Shape = 0b0001001100100000, .Color = { 100, 0, 0, 255 } };
	const Block Z_180 = { .Shape = 0b0000000001100011, .Color = { 100, 0, 0, 255 } };
	const Block Z_270 = { .Shape = 0b0000010011001000, .Color = { 100, 0, 0, 255 } };

	const Block J_0 = { .Shape = 0b0100010011000000, .Color = {  0, 0, 100, 255 } };
	const Block J_90 = { .Shape = 0b0100011100000000, .Color = {  0, 0, 100, 255 } };
	const Block J_180 = { .Shape = 0b0000001100100010, .Color = {  0, 0, 100, 255 } };
	const Block J_270 = { .Shape = 0b0000000011100010, .Color = {  0, 0, 100, 255 } };

	const Block L_0 = { .Shape = 0b1000100011000000, .Color = { 100, 64, 0, 255 } };
	const Block L_90 = { .Shape = 0b0111010000000000, .Color = { 100, 64, 0, 255 } };
	const Block L_180 = { .Shape = 0b0000001100100010, .Color = { 100, 64, 0, 255 } };
	const Block L_270 = { .Shape = 0b0000000000101110, .Color = { 100, 64, 0, 255 } };

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