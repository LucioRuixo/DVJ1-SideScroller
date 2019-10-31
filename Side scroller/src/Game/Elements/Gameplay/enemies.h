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
extern const int INITIAL_HORIZONTAL_SPEED;

extern const float INITIAL_HS_INCREMENT_FACTOR; //HS = horizontal speed

struct Enemy
{
	Color color;
	Rectangle rectangle;

	float horizontalSpeed;
};

extern Enemy enemy;

extern float HSIncrementFactor;

void Initialize();
void Movement();
void Update();
void Draw();
}
}

#endif
