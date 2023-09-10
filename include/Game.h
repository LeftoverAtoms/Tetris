#pragma once

#include "Entity.h"
#include <vector>

class Game
{
public:
	Game();
	~Game();

	void Init(const char* p_title, int x, int y, int w, int h);
	void Events();
	void Update();
	void Render();
	void Quit();

	bool IsActive;

	static inline std::vector<Entity*> Entities;

	static inline SDL_Window* Window;
	static inline SDL_Renderer* Renderer;

private:
	void ConfirmQuit();
};