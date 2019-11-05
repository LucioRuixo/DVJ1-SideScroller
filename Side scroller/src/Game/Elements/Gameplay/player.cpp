#include "Elements/Gameplay/player.h"

#include "game.h"

namespace game
{
namespace player
{
const int WIDTH = 40;
const int HEIGHT = 113;
const int HORIZONTAL_SPEED = 20;
const int VERTICAL_SPEED = 750;

static float animationTimer;
static float animationTimerTarget;

Player player;

void Initialize()
{
	animationTimer = 0;
	animationTimerTarget = 1;

	player.images[0] = LoadImage("images/player/0.png");
	player.images[1] = LoadImage("images/player/1.png");

	for (int i = 0; i < 2; i++)
	{
		player.textures[i] = LoadTextureFromImage(player.images[i]);
	}
	player.currentTexture = player.textures[0];

	player.rectangle.width = static_cast<float>(WIDTH * screenWidthScalar);
	player.rectangle.height = static_cast<float>(HEIGHT * screenHeightScalar);
	player.rectangle.x = static_cast<float>(screenWidth / 10);
	player.rectangle.y = static_cast<float>((screenHeight / 2 - player.rectangle.height / 2) * screenHeightScalar);

	player.horizontalSpeed = HORIZONTAL_SPEED * screenHeightScalar;
	player.verticalSpeed = VERTICAL_SPEED * screenHeightScalar;
}

static void UpdateAnimation()
{
	if (animationTimer > animationTimerTarget)
	{
		player.currentTexture.id == player.textures[0].id ? player.currentTexture = player.textures[1] : player.currentTexture = player.textures[0];
		animationTimer = 0;
	}
}

static void CheckInput()
{
	if (IsKeyDown(KEY_UP) && player.rectangle.y > 0)
		player.rectangle.y -= static_cast<float>(player.verticalSpeed * deltaTime);

	if (IsKeyDown(KEY_DOWN) && player.rectangle.y + player.rectangle.height < screenHeight)
		player.rectangle.y += static_cast<float>(player.verticalSpeed * deltaTime);
}

void Update()
{
	animationTimer += GetFrameTime();

	UpdateAnimation();
	CheckInput();
}

void Draw()
{
	DrawTexture(player.currentTexture, static_cast<int>(player.rectangle.x), static_cast<int>(player.rectangle.y), WHITE);
}

void Close()
{
	for (int i = 1; i >= 0; i--)
	{
		UnloadTexture(player.textures[i]);
		UnloadImage(player.images[i]);
	}
}
}
}