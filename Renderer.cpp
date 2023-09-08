#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include "Renderer.h"

Renderer::Renderer(const char* p_title, int w, int h) : Window(NULL), Reference(NULL)
{
	Window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

	//if (Window == NULL)
	//{
	//	std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	//}

	Reference = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
}
void Renderer::Clear() {
	SDL_RenderClear(Reference);
}
SDL_Texture* Renderer::LoadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(Reference, p_filePath);

	if (texture == NULL)
	{
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
	}

	return texture;
}
void Renderer::Draw(int x, int y, SDL_Texture* p_tex)
{
	SDL_Rect src
	{
		x = x,
		y = y
	};

	// Fetch Texture Size
	SDL_QueryTexture(p_tex, NULL, NULL, &src.w, &src.h);

	SDL_RenderCopy(Reference, p_tex, &src, &src);
}
void Renderer::Render()
{
	SDL_RenderPresent(Reference);
}