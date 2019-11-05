#include "game.h"

#include "States/main_menu.h"
#include "States/credits_screen.h"
#include "States/gameplay.h"
#include "States/game_over.h"
#include "Elements/Gameplay/background.h"
#include "Elements/UI/buttons.h"

namespace game
{
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

GameState currentGameState;
Sound buttonSFX;
Vector2 cursor;

bool fullscreenOn;
bool gameShouldClose;

int screenWidth;
int screenWidthScalar;
int screenHeight;
int screenHeightScalar;
int gradiusFontSize;
int titleFontSize;
int paragraphFontSize;

float deltaTime;

static void InitializeAudio()
{
	InitAudioDevice();

	buttonSFX = LoadSound("audio/SFX/buttonSFX.ogg");
}

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
	titleFontSize = 120 * screenHeightScalar;
	paragraphFontSize = 20 * screenHeightScalar;

	deltaTime = GetFrameTime();

	InitWindow(screenWidth, screenHeight, "GRADIUS!");
	SetExitKey(KEY_E);
	InitializeAudio();
	credits_screen::Initialize();
	gameplay::Initialize();
	buttons::main_menu::Initialize();
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

static void CloseAudio()
{

	UnloadSound(buttonSFX);

	CloseAudioDevice();
}

static void Close()
{
	gameplay::Close();
	CloseAudio();
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

int CenteredTextX(const char* text, int fontSize)
{
	int x = screenWidth / 2 - MeasureText(text, fontSize) / 2;

	return x;
}

int CenteredTextY(int fontSize)
{
	int y = screenHeight / 2 - fontSize / 2;

	return y;
}

int GetTextY(const int ROWS_AMOUNT, int rowNumber)
{
	return ((screenHeight / ROWS_AMOUNT) * rowNumber) - paragraphFontSize / 2;
}
}