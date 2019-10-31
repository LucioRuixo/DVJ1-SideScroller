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

void Update()
{
	if (IsKeyPressed(KEY_SPACE))
		gamePaused = !gamePaused;

	if (!gamePaused)
	{
		player::Update();
		enemies::Update();
	}
}

void Draw()
{
	player::Draw();
	enemies::Draw();

	if (gamePaused)
		DrawText("Game paused", CenteredTextX("Game paused", PARAGRAPH_FONT_SIZE), screenHeight / 3, PARAGRAPH_FONT_SIZE, RAYWHITE);
}
}
}