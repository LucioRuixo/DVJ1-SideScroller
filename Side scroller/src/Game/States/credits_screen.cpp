#include "States/credits_screen.h"

#include "raylib.h"

#include "game.h"

namespace game
{
namespace credits_screen
{
static const int ROWS_AMOUNT = 25;

static int textX;

void Initialize()
{
	textX = screenWidth / 10;
}

static void CheckInput()
{
	if (IsKeyPressed(KEY_ENTER))
	{
		currentGameState = MainMenu;

		PlaySound(buttonSFX);
	}
}

void Update()
{
	CheckInput();
}

static void DrawScreenText()
{
	DrawText("PROGRAMMER: Lucio Ruixo", textX, GetTextY(ROWS_AMOUNT, 2), paragraphFontSize, RAYWHITE);
	DrawText("VERSION: 0.2", textX, GetTextY(ROWS_AMOUNT, 3), paragraphFontSize, RAYWHITE);
	DrawText("TOOLS:", textX, GetTextY(ROWS_AMOUNT, 5), paragraphFontSize, RAYWHITE);
	DrawText("Library: RayLib 2.5.0 Win32 ... www.raylib.com/", textX, GetTextY(ROWS_AMOUNT, 6), paragraphFontSize, RAYWHITE);
	DrawText("IDE: Microsoft Visual Studio 2017 ... visualstudio.microsoft.com/", textX, GetTextY(ROWS_AMOUNT, 7), paragraphFontSize, RAYWHITE);
	DrawText("Audio editing: Audacity 2.3.2 ... www.audacityteam.org/", textX, GetTextY(ROWS_AMOUNT, 8), paragraphFontSize, RAYWHITE);
	DrawText("IMAGES:", textX, GetTextY(ROWS_AMOUNT, 10), paragraphFontSize, RAYWHITE);
	DrawText("Kenney Vleugels - 'Space Shooter Redux' ... www.kenney.nl/assets/space-shooter-redux", textX, GetTextY(ROWS_AMOUNT, 11), paragraphFontSize, RAYWHITE);
	DrawText("DINV STUDIO - 'Planets with Space Background in Flat Style' ... assetstore.unity.com/packages/   ->", textX, GetTextY(ROWS_AMOUNT, 12), paragraphFontSize, RAYWHITE);
	DrawText("2d/textures-materials/planets-with-space-background-in-flat-style-95983", textX, GetTextY(ROWS_AMOUNT, 13), paragraphFontSize, RAYWHITE);
	DrawText("SOUND EFFECTS:", textX, GetTextY(ROWS_AMOUNT, 15), paragraphFontSize, RAYWHITE);
	DrawText("ZapSplat - 'Multimedia plastic style button click 3' ... www.zapsplat.com/", textX, GetTextY(ROWS_AMOUNT, 16), paragraphFontSize, RAYWHITE);
	DrawText("Exposed Tv - 'Pong Sound Effect' ... www.youtube.com/watch?v=IExAq3GBRvI", textX, GetTextY(ROWS_AMOUNT, 17), paragraphFontSize, RAYWHITE);
	DrawText("MUSIC:", textX, GetTextY(ROWS_AMOUNT, 19), paragraphFontSize, RAYWHITE);
	DrawText("Tyler River - 'Solemn Mood Chiptune' ... https://youtu.be/7M6Y7ROT-u8?t=94", textX, GetTextY(ROWS_AMOUNT, 20), paragraphFontSize, RAYWHITE);
	DrawText("Press Enter to continue", textX, GetTextY(ROWS_AMOUNT, ROWS_AMOUNT - 2), paragraphFontSize, RAYWHITE);
}

void Draw()
{
	DrawScreenText();
}
}
}