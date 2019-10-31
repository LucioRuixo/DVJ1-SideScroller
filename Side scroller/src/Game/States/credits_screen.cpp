#include "States/credits_screen.h"

#include "raylib.h"

#include "game.h"

namespace game
{
namespace credits_screen
{
void Update()
{
	if (IsKeyPressed(KEY_ENTER))
		currentGameState = MainMenu;
}

static void DrawScreenText()
{
	DrawText("PROGRAMMER: Lucio Ruixo", screenWidth / 6, ((screenHeight / 10) * 4) - paragraphFontSize / 2, paragraphFontSize, RAYWHITE);
	DrawText("VERSION: 0.1", screenWidth / 6, ((screenHeight / 10) * 5) - paragraphFontSize / 2, paragraphFontSize, RAYWHITE);
	DrawText("Press Enter to continue", screenWidth / 6, ((screenHeight / 10) * 7) - paragraphFontSize / 2, paragraphFontSize, RAYWHITE);
}

void Draw()
{
	DrawScreenText();
}
}
}