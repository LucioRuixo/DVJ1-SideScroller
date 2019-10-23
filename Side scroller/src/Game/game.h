#ifndef GAME_H
#define GAME_H

#include "raylib.h"

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
extern Vector2 cursor;

extern bool fullscreenOn;
extern bool gameShouldClose;

extern int screenWidth;
extern int screenWidthScalar;
extern int screenHeight;
extern int screenHeightScalar;

void Execute();
}

#endif