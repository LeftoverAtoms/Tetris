#pragma once

#include <SDL.h>

class Input
{
public:
	static SDL_KeyboardEvent Key;

	static bool Pressed(SDL_Keycode keycode);
	static bool Released(SDL_Keycode keycode);
};