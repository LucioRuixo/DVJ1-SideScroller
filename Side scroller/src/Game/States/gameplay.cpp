#include "gameplay.h"

#include "raylib.h"

#include "Elements/Gameplay/background.h"
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

	background::InitializeLayer1();
	background::InitializeLayer2();
	player::Initialize();
	enemies::Initialize();
}

static void CheckCollisions()
{
	if (CheckCollisionRecs(player::player.rectangle, enemies::enemy.rectangle))
	{
		currentGameState = GameOver;
		Initialize();
	}
}

void Update()
{
	if (IsKeyPressed(KEY_SPACE))
		gamePaused = !gamePaused;

	if (!gamePaused)
	{
		background::Update();
		player::Update();
		enemies::Update();

		CheckCollisions();
	}
}

void Draw()
{
	background::Draw();
	player::Draw();
	enemies::Draw();

	if (gamePaused)
		DrawText("Game paused", CenteredTextX("Game paused", paragraphFontSize), screenHeight / 3, paragraphFontSize, RAYWHITE);
}

void Close()
{
	background::Close();
}
}
}