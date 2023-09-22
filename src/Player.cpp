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
			if (Input::Pressed(SDLK_a))
			{
				Blocks[x][y]->Transform.x -= 32;
			}
			if (Input::Pressed(SDLK_d))
			{
				Blocks[x][y]->Transform.x += 32;
			}
			if (Input::Pressed(SDLK_w))
			{
				Blocks[x][y]->Transform.y -= 32;
			}
			if (Input::Pressed(SDLK_s))
			{
				Blocks[x][y]->Transform.y += 32;
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
			int bit = (32768 >> i++) & block.Shape;

			Entity* ent = Blocks[x][y];

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