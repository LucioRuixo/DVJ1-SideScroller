#include "enemies.h"

namespace game
{
namespace enemies
{
static const int INITIAL_HORIZONTAL_SPEED = 1000;

static const float INITIAL_HS_INCREASE_FACTOR = 0.01f;

const int WIDTH = 100;
const int HEIGHT = 40;

static float HSIncreaseFactor;

Enemy enemy;

void Initialize()
{
	enemy.color = RED;
	enemy.rectangle.width = static_cast<float>(WIDTH * screenWidthScalar);
	enemy.rectangle.height = static_cast<float>(HEIGHT * screenWidthScalar);
	enemy.rectangle.x = static_cast<float>(screenWidth);
	enemy.rectangle.y = static_cast<float>(GetRandomValue(0, screenHeight - HEIGHT * screenHeightScalar));
	enemy.horizontalSpeed = static_cast<float>(INITIAL_HORIZONTAL_SPEED * screenWidthScalar);

	HSIncreaseFactor = INITIAL_HS_INCREASE_FACTOR * screenWidthScalar;
}

static void Movement()
{
	if (enemy.rectangle.x > -enemy.rectangle.width - screenWidthScalar)
		enemy.rectangle.x -= enemy.horizontalSpeed * deltaTime;
	else
	{
		enemy.rectangle.x = static_cast<float>(screenWidth);
		enemy.rectangle.y = static_cast<float>(GetRandomValue(0, screenHeight - HEIGHT * screenHeightScalar));
	}

	enemy.horizontalSpeed += HSIncreaseFactor;
}

void Update()
{
	Movement();
}

void Draw()
{
	DrawRectangle(static_cast<int>(enemy.rectangle.x), static_cast<int>(enemy.rectangle.y), static_cast<int>(enemy.rectangle.width), static_cast<int>(enemy.rectangle.height), enemy.color);
}
}
}