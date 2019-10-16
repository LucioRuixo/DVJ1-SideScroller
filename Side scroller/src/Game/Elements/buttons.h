#ifndef BUTTONS_H
#define BUTTONS_H

#include "raylib.h"

#include "game.h"

namespace game
{
namespace buttons
{
enum Function
{
	ActivateFullscreen,
	ChangeState,
	ExitGame,
};

struct GeneralButton
{
	Function function;
	Rectangle rec;

	const char* text;

	bool cursorOverButton;
};

struct StateChangerButton
{
	Function function;
	GameState state;
	Rectangle rec;

	const char* text;

	bool cursorOverButton;
};

extern GeneralButton continue_;
extern GeneralButton exit;
extern GeneralButton pause;

extern StateChangerButton play;
extern StateChangerButton return_;

namespace main_menu
{
	extern float buttonsX;

	void Initialize();
}
namespace gameplay
{
	void Initialize();
}

void CheckPressingGeneral(GeneralButton button);
void UpdateGeneral(GeneralButton &button);
void DrawGeneral(GeneralButton button);
void CheckPressingStateChanger(StateChangerButton button);
void UpdateStateChanger(StateChangerButton &button);

void DrawGeneral(GeneralButton button);
void DrawStateChanger(StateChangerButton button);

bool CursorOverButton(Button button);
}
}

#endif