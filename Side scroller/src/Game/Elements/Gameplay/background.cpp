#include "background.h"

#include "game.h"

namespace game
{
namespace background
{
const int PLANETS_AMOUNT = 5;
const int PLANETS_SIZE = 150;
const int STARS_AMOUNT = 100;
const int STARS_MIN_RADIUS = 1;
const int STARS_MAX_RADIUS = 3;

static bool texturesLoaded;

const float PLANETS_SPEED = 0.1f;;
const float STARS_SPEED = 0.05f;

Planet planets[PLANETS_AMOUNT];
Star stars[STARS_AMOUNT];

void InitializeLayer1()
{
	for (int i = 0; i < STARS_AMOUNT; i++)
	{
		stars[i].position = { static_cast<float>(GetRandomValue(0, screenWidth)), static_cast<float>(GetRandomValue(0, screenHeight)) };
		stars[i].radius = static_cast<float>(GetRandomValue(STARS_MIN_RADIUS, STARS_MAX_RADIUS) * screenWidthScalar);
	}
}

void InitializeLayer2()
{
	if (!texturesLoaded)
	{

		planets[0].image = LoadImage("images/planets/0.png");
		planets[1].image = LoadImage("images/planets/1.png");
		planets[2].image = LoadImage("images/planets/2.png");
		planets[3].image = LoadImage("images/planets/3.png");
		planets[4].image = LoadImage("images/planets/4.png");

		for (int i = 0; i < PLANETS_AMOUNT; i++)
		{
			planets[i].color = {175, 175, 175, 255};

			ImageResize(&planets[i].image, PLANETS_SIZE * screenWidthScalar, PLANETS_SIZE * screenWidthScalar);

			planets[i].texture = LoadTextureFromImage(planets[i].image);
		}

		texturesLoaded = true;
	}

	for (int i = 0; i < PLANETS_AMOUNT; i++)
	{
		planets[i].position = { static_cast<float>(GetRandomValue(0, screenWidth)), static_cast<float>(GetRandomValue(0, screenHeight)) };
	}
}

void Initialize()
{
	texturesLoaded = false;

	InitializeLayer1();
	InitializeLayer2();
}

void UpdateLayer1()
{
	for (int i = 0; i < STARS_AMOUNT; i++)
	{
		stars[i].position.x -= STARS_SPEED * screenWidthScalar;

		if (stars[i].position.x + stars[i].radius < 0)
			stars[i].position.x = screenWidth + stars[i].radius;
	}
}

void UpdateLayer2()
{
	for (int i = 0; i < PLANETS_AMOUNT; i++)
	{
		planets[i].position.x -= PLANETS_SPEED * screenWidthScalar;

		if (planets[i].position.x + PLANETS_SIZE < 0)
		{
			planets[i].position.x = { static_cast<float>(screenWidth + GetRandomValue(0, screenWidth / 3)) };
			planets[i].position.y = { static_cast<float>(GetRandomValue(0, screenHeight)) };
		}
			
	}
}

void Update()
{
	UpdateLayer1();
	UpdateLayer2();
}

void DrawLayer1()
{
	for (int i = 0; i < STARS_AMOUNT; i++)
	{
		DrawCircle(static_cast<int>(stars[i].position.x), static_cast<int>(stars[i].position.y), stars[i].radius, RAYWHITE);
	}
}

void DrawLayer2()
{
	for (int i = 0; i < PLANETS_AMOUNT; i++)
	{
		DrawTextureV(planets[i].texture, planets[i].position, planets[i].color);
	}
}

void Draw()
{
	DrawLayer1();
	DrawLayer2();
}

void Close()
{
	for (int i = 0; i < PLANETS_AMOUNT; i++)
	{
		UnloadTexture(planets[i].texture);
		UnloadImage(planets[i].image);
	}
}
}
}