#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "raylib.h"

using namespace std;

namespace game
{
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

enum GameState
{
	MainMenu,
	CreditsScreen,
	Gameplay,
	GameOver
};

extern GameState currentGameState;
extern Sound buttonSFX;
extern Vector2 cursor;

extern bool fullscreenOn;
extern bool gameShouldClose;

extern int screenWidth;
extern int screenWidthScalar;
extern int screenHeight;
extern int screenHeightScalar;
extern int titleFontSize;
extern int paragraphFontSize;

extern float deltaTime;

void Execute();

int CenteredTextX(const char* text, int fontSize);
int CenteredTextY(int fontSize);
int GetTextY(const int ROWS_AMOUNT, int rowNumber);
}

#endif