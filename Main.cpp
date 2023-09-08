#include <SDL.h>

#include "Renderer.h"

Renderer window("Tetris", 640, 480);

SDL_Texture* bgTexture = window.LoadTexture("res/blue_frog.png");

int main(int argc, char* args[])
{
	// Subsystems
	SDL_Init(SDL_INIT_EVERYTHING);

	window.Clear();
	window.Draw(0, 0, bgTexture);
	window.Render();

	SDL_Event event;
	for (;;)
	{
		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT)
		{
			const SDL_MessageBoxButtonData buttons[] =
			{
				{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "No" },
				{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "Yes" },
			};

			const SDL_MessageBoxData data =
			{
				SDL_MESSAGEBOX_INFORMATION,
				NULL,
				"Are you sure you want to quit?",
				"Are you sure you want to quit?",
				2,
				buttons,
				NULL
			};

			int buttonid;
			SDL_ShowMessageBox(&data, &buttonid);

			if (buttonid == 0)
			{
				SDL_Log("Program quit after %i ticks", event.quit.timestamp);
				break;
			}
		}
	}

	return 0;
}

