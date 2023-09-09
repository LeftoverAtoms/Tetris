#pragma once

#include<SDL.h>

class Renderer
{
public:
	Renderer(const char* p_title, int w, int h);
	void Clear();
	SDL_Texture* LoadTexture(const char* p_filePath);
	void Draw(int x, int y, SDL_Texture* p_tex);
	void Render();
private:
	SDL_Window* Window;
	SDL_Renderer* Reference;
};