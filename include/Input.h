#pragma once

#include <SDL.h>

class Input
{
public:
	static bool Pressed(SDL_Keycode keycode);
	static bool Released(SDL_Keycode keycode);

	static inline SDL_KeyboardEvent Key;
};