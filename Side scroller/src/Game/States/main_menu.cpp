#include "main_menu.h"

#include "Elements/UI/buttons.h"

namespace game
{
namespace main_menu
{
const int ROWS_AMOUNT = 21;

void Update()
{
	buttons::Update(buttons::play);
	buttons::Update(buttons::credits);
	buttons::Update(buttons::exit);
}

void Draw()
{
	DrawText("GRADIUS!", CenteredTextX("GRADIUS!", titleFontSize), GetTextY(ROWS_AMOUNT, 2), titleFontSize, RAYWHITE);
	buttons::Draw(buttons::play);
	buttons::Draw(buttons::credits);
	buttons::Draw(buttons::exit);
	DrawText("Press 'E' to exit", CenteredTextX("Press 'E' to exit", paragraphFontSize), GetTextY(ROWS_AMOUNT, 16), paragraphFontSize, RAYWHITE);
	DrawText("DURING GAMEPLAY:", CenteredTextX("DURING GAMEPLAY:", paragraphFontSize), GetTextY(ROWS_AMOUNT, 17), paragraphFontSize, RAYWHITE);
	DrawText("Press 'M' to mute the music", CenteredTextX("Press 'M' to mute the music", paragraphFontSize), GetTextY(ROWS_AMOUNT, 18), paragraphFontSize, RAYWHITE);
	DrawText("Press 'SPACE' to pause the game", CenteredTextX("Press 'SPACE' to pause the game", paragraphFontSize), GetTextY(ROWS_AMOUNT, 19), paragraphFontSize, RAYWHITE);
}
}
}