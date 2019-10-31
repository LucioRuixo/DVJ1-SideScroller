#include "buttons.h"

#include "raylib.h"

#include "game.h"

namespace game
{
namespace buttons
{
Button credits;
Button exit;
Button pause;
Button play;
Button return_;

namespace main_menu
{
void Initialize()
{
	play.function = Function::ChangeState;
	play.state = GameState::Gameplay;
	play.text = "PLAY";
	play.fontSize = paragraphFontSize;
	play.rectangle.width = static_cast<float>(MeasureText(play.text, play.fontSize) * screenWidthScalar);
	play.rectangle.height = static_cast<float>(play.fontSize * screenHeightScalar);
	play.rectangle.x = static_cast<float>(CenteredTextX(play.text, play.fontSize) * screenWidthScalar);
	play.rectangle.y = static_cast<float>(((screenHeight / 9) * 4) * screenHeightScalar);

	credits.function = Function::ChangeState;
	credits.state = GameState::CreditsScreen;
	credits.text = "Credits";
	credits.fontSize = paragraphFontSize;
	credits.rectangle.width = static_cast<float>(MeasureText(credits.text, credits.fontSize) * screenWidthScalar);
	credits.rectangle.height = static_cast<float>(credits.fontSize * screenHeightScalar);
	credits.rectangle.x = static_cast<float>(CenteredTextX(credits.text, credits.fontSize) * screenWidthScalar);
	credits.rectangle.y = static_cast<float>(((screenHeight / 9) * 5) * screenHeightScalar);

	exit.function = Function::ExitGame;
	exit.text = "Exit";
	exit.fontSize = paragraphFontSize;
	exit.rectangle.width = static_cast<float>(MeasureText(exit.text, exit.fontSize) * screenWidthScalar);
	exit.rectangle.height = static_cast<float>(exit.fontSize * screenHeightScalar);
	exit.rectangle.x = static_cast<float>(CenteredTextX(exit.text, exit.fontSize) * screenWidthScalar);
	exit.rectangle.y = static_cast<float>(((screenHeight / 9) * 6) * screenHeightScalar);
}
}

namespace game_over
{
void Initialize()
{
	return_.function = Function::ChangeState;
	return_.state = GameState::MainMenu;
	return_.rectangle.width = 9.0f * screenWidthScalar;
	return_.rectangle.height = 3.0f * screenHeightScalar;
	return_.rectangle.x = 1.0f * screenWidthScalar;
	return_.rectangle.y = 1.0f * screenHeightScalar;
	return_.text = "< Return";
}
}

void Update(Button &button)
{
	if (CursorOverButton(button))
	{
		button.cursorOverButton = true;

		CheckPressing(button);
	}
	else
		button.cursorOverButton = false;
}

void CheckPressing(Button button)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		//PlaySound(buttonSFX);

		switch (button.function)
		{
		case Function::ChangeState:
			currentGameState = button.state;
			break;
		case Function::ExitGame:
			gameShouldClose = true;
			break;
		case Function::ActivateFullscreen:
			if (!fullscreenOn)
			{
				screenWidth = GetMonitorWidth(0);
				screenHeight = GetMonitorHeight(0);
				ToggleFullscreen();
			}
			else
			{
				screenWidth = WINDOW_WIDTH;
				screenHeight = WINDOW_HEIGHT;
				ToggleFullscreen();
			}
			break;
		}
	}
}

void Draw(Button button)
{
	if (button.cursorOverButton)
	{
		DrawRectangle(static_cast<int>(button.rectangle.x - 0.5f * screenWidthScalar), static_cast<int>(button.rectangle.y - 0.5f * screenHeightScalar), static_cast<int>(button.rectangle.width), static_cast<int>(button.rectangle.height), RAYWHITE);
		DrawText(button.text, static_cast<int>(button.rectangle.x), static_cast<int>(button.rectangle.y), 20, BLACK);
	}
	else
		DrawText(button.text, static_cast<int>(button.rectangle.x), static_cast<int>(button.rectangle.y), 20, RAYWHITE);
}

bool CursorOverButton(Button button)
{
	if ((cursor.x > button.rectangle.x && cursor.x < button.rectangle.x + button.rectangle.width)
		&&
		(cursor.y > button.rectangle.y && cursor.y < button.rectangle.y + button.rectangle.height))
	{
		return true;
	}
	else
		return false;
}
}
}