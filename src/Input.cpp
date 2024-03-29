#include "Input.h"
#include <iostream>

SDL_KeyboardEvent Input::Key = {};

bool Input::Pressed(SDL_Keycode keycode)
{
	if (Input::Key.state == SDL_PRESSED)
	{
		if (Input::Key.keysym.sym == keycode)
		{
			// Breaks input system?
			//Input::Key = SDL_KeyboardEvent();

			return true;
		}
	}
	return false;
}
bool Input::Released(SDL_Keycode keycode)
{
	if (Key.state == SDL_RELEASED)
	{
		if (Key.keysym.sym == keycode)
		{
			// Reset Input
			Key = SDL_KeyboardEvent();

			return true;
		}
	}
	return false;
}