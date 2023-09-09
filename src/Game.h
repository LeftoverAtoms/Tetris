#pragma once
#include<SDL.h>

class Game
{
public:
	Game();
	~Game();

	void Init(const char* p_title, int x, int y, int w, int h);
	void Events();
	void Update();
	void Render();
	void Clean();

	bool Active();

private:
	void Quit();

	bool IsActive;

	SDL_Window* Window;
	SDL_Renderer* Renderer;
};