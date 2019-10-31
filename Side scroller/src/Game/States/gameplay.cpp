#include "gameplay.h"

#include "raylib.h"

#include "Elements/Gameplay/enemies.h"
#include "Elements/Gameplay/player.h"

namespace game
{
namespace gameplay
{
static bool gamePaused;

void Initialize()
{
	gamePaused = false;

	player::Initialize();
	enemies::Initialize();
}

static void CheckCollisions()
{
	if (CheckCollisionRecs(player::player.rectangle, enemies::enemy.rectangle))
		currentGameState = GameOver;
}

void Update()
{
	if (IsKeyPressed(KEY_SPACE))
		gamePaused = !gamePaused;

	if (!gamePaused)
	{
		player::Update();
		enemies::Update();

		CheckCollisions();
	}
}

void Draw()
{
	player::Draw();
	enemies::Draw();

	if (gamePaused)
		DrawText("Game paused", CenteredTextX("Game paused", paragraphFontSize), screenHeight / 3, paragraphFontSize, RAYWHITE);
}
}
}