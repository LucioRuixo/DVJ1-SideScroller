#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace game
{
namespace player
{
extern const int WIDTH;
extern const int HEIGHT;
extern const int HORIZONTAL_SPEED;
extern const int VERTICAL_SPEED;

struct Player
{
	Color color;
	Rectangle rectangle;

	int horizontalSpeed;
	int verticalSpeed;
};

extern Player player;

void Initialize();
void Input();
void Update();
void Draw();
}
}

#endif