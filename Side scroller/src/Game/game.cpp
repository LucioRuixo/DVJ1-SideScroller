#include "game.h"

#include "States/main_menu.h"
#include "States/credits_screen.h"
#include "States/gameplay.h"
#include "States/game_over.h"
#include "Elements/UI/buttons.h"

namespace game
{
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

GameState currentGameState;
Vector2 cursor;

bool fullscreenOn;
bool gameShouldClose;

int screenWidth;
int screenWidthScalar;
int screenHeight;
int screenHeightScalar;

float deltaTime;

static void Initialize()
{
	currentGameState = MainMenu;
	cursor = GetMousePosition();

	fullscreenOn = false;
	gameShouldClose = false;

	screenWidth = WINDOW_WIDTH;
	screenWidthScalar = screenWidth / WINDOW_WIDTH;
	screenHeight = WINDOW_HEIGHT;
	screenHeightScalar = screenHeight / WINDOW_HEIGHT;

	deltaTime = GetFrameTime();

	InitWindow(screenWidth, screenHeight, "GRADIUS!");
	buttons::main_menu::Initialize();
	//credits_screen::Initialize();
	gameplay::Initialize();
}

static void Update()
{
	cursor = GetMousePosition();

	deltaTime = GetFrameTime();

	switch (currentGameState)
	{
	case MainMenu:
		main_menu::Update();
		break;
	case CreditsScreen:
		credits_screen::Update();
		break;
	case Gameplay:
		gameplay::Update();
		break;
	case GameOver:
		game_over::Update();
		break;
	}
}

static void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	switch (currentGameState)
	{
	case MainMenu:
		main_menu::Draw();
		break;
	case CreditsScreen:
		credits_screen::Draw();
		break;
	case Gameplay:
		gameplay::Draw();
		break;
	case GameOver:
		game_over::Draw();
		break;
	}

	EndDrawing();
}

static void Close()
{
	CloseWindow();
}

void Execute()
{
	Initialize();

	while (!gameShouldClose)
	{
		if (!WindowShouldClose())
		{
			Update();

			Draw();
		}
		else
			gameShouldClose = true;
	}

	Close();
}
}