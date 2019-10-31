#include "buttons.h"

#include "raylib.h"

#include "game.h"

namespace game
{
namespace buttons
{
Button exit;
Button fullScreen_;
Button pause;
Button play;
Button return_;

namespace main_menu
{
float buttonsX;

void Initialize()
{
	buttonsX = static_cast<float>(screenWidth) / 6.0f;

	exit.function = Function::ExitGame;
	exit.rectangle.width = 4.0f * screenWidthScalar;
	exit.rectangle.height = 4.0f * screenHeightScalar;
	exit.rectangle.x = buttonsX;
	exit.rectangle.y = (static_cast<float>(screenHeight) / 3.0f) * 2 + 40;
	exit.text = "Exit";

	fullScreen_.function = Function::ActivateFullscreen;
	fullScreen_.rectangle.width = 10.0f * screenWidthScalar;
	fullScreen_.rectangle.height = 4.0f * screenHeightScalar;
	fullScreen_.rectangle.x = screenWidth - fullScreen_.rectangle.width - 1.0f * screenWidthScalar;
	fullScreen_.rectangle.y = 1.0f * screenHeightScalar;
	fullScreen_.text = "Fullscreen";

	play.function = Function::ChangeState;
	play.state = GameState::Gameplay;
	play.text = "PLAY";
	play.fontSize = PARAGRAPH_FONT_SIZE;
	play.rectangle.width = static_cast<float>(MeasureText(play.text, play.fontSize) * screenWidthScalar);
	play.rectangle.height = static_cast<float>(play.fontSize * screenHeightScalar);
	play.rectangle.x = static_cast<float>(CenteredTextX(play.text, play.fontSize) * screenWidthScalar);
	play.rectangle.y = static_cast<float>(CenteredTextY(play.fontSize) * screenHeightScalar);
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