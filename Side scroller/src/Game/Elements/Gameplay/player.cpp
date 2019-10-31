#include "Elements/Gameplay/player.h"

#include "game.h"

namespace game
{
namespace player
{
const int WIDTH = 75;
const int HEIGHT = 25;
const int HORIZONTAL_SPEED = 20;
const int VERTICAL_SPEED = 750;

Player player;

void Initialize()
{
	player.color = BLUE;
	player.rectangle.width = static_cast<float>(WIDTH * screenWidthScalar);
	player.rectangle.height = static_cast<float>(HEIGHT * screenHeightScalar);
	player.rectangle.x = static_cast<float>(screenWidth / 10);
	player.rectangle.y = static_cast<float>((screenHeight / 2 - player.rectangle.height / 2) * screenHeightScalar);
	player.horizontalSpeed = HORIZONTAL_SPEED * screenHeightScalar;
	player.verticalSpeed = VERTICAL_SPEED * screenHeightScalar;
}

void Input()
{
	if (IsKeyDown(KEY_UP) && player.rectangle.y > 0)
		player.rectangle.y -= static_cast<float>(player.verticalSpeed * deltaTime);

	if (IsKeyDown(KEY_DOWN) && player.rectangle.y + player.rectangle.height < screenHeight)
		player.rectangle.y += static_cast<float>(player.verticalSpeed * deltaTime);
}

void Update()
{
	Input();
}

void Draw()
{
	DrawRectangle(static_cast<int>(player.rectangle.x), static_cast<int>(player.rectangle.y), static_cast<int>(player.rectangle.width), static_cast<int>(player.rectangle.height), player.color);
}
}
}