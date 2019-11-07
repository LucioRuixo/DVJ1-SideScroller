#ifndef  ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

#include "game.h"

namespace game
{
namespace enemies
{
struct Enemy
{
	Color color;
	Rectangle rectangle;

	float horizontalSpeed;
};

extern Enemy enemy;

void Initialize();
void Update();
void Draw();
}
}

#endif
