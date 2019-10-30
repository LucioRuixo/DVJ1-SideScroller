#ifndef BUTTONS_H
#define BUTTONS_H

#include "raylib.h"

#include "game.h"

namespace game
{
namespace buttons
{
const int TITLE_FONT_SIZE = 30;
const int PARAGRAPH_FONT_SIZE = 20;

enum Function
{
	ActivateFullscreen,
	ChangeState,
	ExitGame,
};

struct Button
{
	Function function;
	GameState state;
	Rectangle rectangle;

	const char* text;

	bool cursorOverButton;

	int fontSize;
};

extern Button continue_;
extern Button exit;
extern Button pause;

extern Button play;
extern Button return_;

namespace main_menu
{
extern float buttonsX;

void Initialize();
}
namespace gameplay
{
void Initialize();
}

void CheckPressing(Button button);
void Update(Button &button);
void Draw(Button button);

bool CursorOverButton(Button button);

int CenteredX(Button button);
int CenteredY(Button button);
}
}

#endif