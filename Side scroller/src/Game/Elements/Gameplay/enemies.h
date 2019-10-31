#ifndef  ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

#include "game.h"

namespace game
{
namespace enemies
{
extern const int WIDTH;
extern const int HEIGHT;

struct Enemy
{
	Color color;
	Rectangle rectangle;

	float horizontalSpeed;
};

extern Enemy enemy;

void Initialize();
static void Movement();
void Update();
void Draw();
}
}

#endif
