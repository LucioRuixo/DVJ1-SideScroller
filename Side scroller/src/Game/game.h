#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "raylib.h"

using namespace std;

namespace game
{
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int TITLE_FONT_SIZE;
extern const int PARAGRAPH_FONT_SIZE;

enum GameState
{
	MainMenu,
	CreditsScreen,
	Gameplay,
	GameOver
};

extern GameState currentGameState;
extern Vector2 cursor;

extern bool fullscreenOn;
extern bool gameShouldClose;

extern int screenWidth;
extern int screenWidthScalar;
extern int screenHeight;
extern int screenHeightScalar;

extern float deltaTime;

void Execute();
}

#endif