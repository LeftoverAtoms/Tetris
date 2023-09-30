#include <Game.h>
#include <iostream>
#include "Input.h"
#include "Player.h"

Player* Player::Instance;

Player::Player()
{
	Entity::SetTexture("res/blue_frog.png");
	Instance = this;
}
Player::~Player() {}

void Player::Update()
{
	Entity::Update();

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			Entity* ent = Blocks[x][y];

			if (!ent->Active)
				continue;

			if (Input::Pressed(SDLK_q))
			{
				if (Rotation == 0)
				{
					Rotation = 90;
					ParseBlock(Game::J_90);
				}
				else if (Rotation == 90)
				{
					Rotation = 180;
					ParseBlock(Game::J_180);
				}
				else if (Rotation == 180)
				{
					Rotation = 270;
					ParseBlock(Game::J_270);
				}
				else if (Rotation == 270)
				{
					Rotation = 0;
					ParseBlock(Game::J_0);
				}
			}

			std::cout << Rotation << std::endl;

			if (Input::Pressed(SDLK_a))
			{
				ent->Transform.x -= 32;
			}
			if (Input::Pressed(SDLK_d))
			{
				ent->Transform.x += 32;
			}
			if (Input::Pressed(SDLK_w))
			{
				ent->Transform.y -= 32;
			}
			if (Input::Pressed(SDLK_s))
			{
				ent->Transform.y += 32;
			}
		}
	}
}

void Player::ParseBlock(Block block)
{
	int i = 0;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			Entity* ent = Blocks[x][y];

			unsigned short bit = (0b1000000000000000 >> i++) & block.Shape;

			if (ent == NULL)
			{
				ent = new Entity();
			}

			if (bit != NULL)
			{
				ent->SetTexture("res/cat.png");
				ent->SetPosition(32 * (4 + x), 32 * (1 + y));
				ent->SetScale(32, 32);

				ent->Active = true;
			}
			else
			{
				ent->Active = false;
			}

			Blocks[x][y] = ent;
		}
	}
}