#include "Input.h"
#include <SDL.h>

SDL_KeyboardEvent Input::Key = SDL_KeyboardEvent();

bool Input::Pressed(SDL_Keycode keycode)
{
	if (Input::Key.state == SDL_PRESSED)
	{
		if (Input::Key.keysym.sym == keycode)
		{
			// Reset Input
			Key = SDL_KeyboardEvent();

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