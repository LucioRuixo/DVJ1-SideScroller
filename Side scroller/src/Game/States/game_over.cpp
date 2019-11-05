#include "States/game_over.h"

#include "raylib.h"

#include "game.h"

namespace game
{
namespace game_over
{
void Update()
{
	if (IsKeyPressed(KEY_ENTER))
	{
		currentGameState = MainMenu;

		PlaySound(buttonSFX);
	}
}

static void DrawScreenText()
{
	DrawText("GAME OVER", CenteredTextX("GAME OVER", paragraphFontSize), (screenHeight / 10) * 5 - paragraphFontSize / 2, paragraphFontSize, RAYWHITE);
	DrawText("Press Enter to continue", CenteredTextX("Press Enter to continue", paragraphFontSize), (screenHeight / 10) * 6 - paragraphFontSize / 2, paragraphFontSize, RAYWHITE);
}

void Draw()
{
	DrawScreenText();
}
}
}