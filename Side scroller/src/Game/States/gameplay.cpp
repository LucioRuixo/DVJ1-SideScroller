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

Music music;

void Initialize()
{
	music = LoadMusicStream("audio/music/music.ogg");

	gamePaused = false;

	background::Initialize();
	player::Initialize();
	enemies::Initialize();
}

static void CheckInput()
{
	if (IsKeyPressed(KEY_M))
		IsMusicPlaying(music) ? PauseMusicStream(music) : ResumeMusicStream(music);

	if (IsKeyPressed(KEY_SPACE))
	{
		gamePaused = !gamePaused;

		PlaySound(buttonSFX);
	}
}

static void CheckCollisions()
{
	if (CheckCollisionRecs(player::player.rectangle, enemies::enemy.rectangle))
	{
		currentGameState = GameOver;

		if (IsMusicPlaying(music))
			StopMusicStream(music);
	}
}

void Update()
{
	UpdateMusicStream(music);

	CheckInput();

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
	player::Close();
	background::Close();

	UnloadMusicStream(music);
}
}
}