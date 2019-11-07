#include "background.h"

#include "game.h"

namespace game
{
namespace background
{
static const Color PLANETS_COLOR = { 175, 175, 175, 255 };

static const int PLANETS_AMOUNT = 5;
static const int STARS_AMOUNT = 100;

Planet planets[PLANETS_AMOUNT];
Star stars[STARS_AMOUNT];

static int planetsSize;
static int starsMinRadius;
static int starsMaxRadius;

static void InitializeLayer1()
{
	starsMinRadius = 1 * screenWidthScalar;
	starsMaxRadius = 3 * screenWidthScalar;

	for (int i = 0; i < STARS_AMOUNT; i++)
	{
		stars[i].position = { static_cast<float>(GetRandomValue(0, screenWidth)), static_cast<float>(GetRandomValue(0, screenHeight)) };
		stars[i].radius = GetRandomValue(starsMinRadius, starsMaxRadius) * screenWidthScalar;
		stars[i].speed = 90 * screenWidthScalar;
	}
}

static void InitializeLayer2()
{
	planetsSize = 150 * screenWidthScalar;

	planets[0].image = LoadImage("images/planets/0.png");
	planets[1].image = LoadImage("images/planets/1.png");
	planets[2].image = LoadImage("images/planets/2.png");
	planets[3].image = LoadImage("images/planets/3.png");
	planets[4].image = LoadImage("images/planets/4.png");

	for (int i = 0; i < PLANETS_AMOUNT; i++)
	{
		planets[i].color = PLANETS_COLOR;
		ImageResize(&planets[i].image, planetsSize, planetsSize);
		planets[i].texture = LoadTextureFromImage(planets[i].image);
		planets[i].position = { static_cast<float>(GetRandomValue(0, screenWidth)), static_cast<float>(GetRandomValue(0, screenHeight)) };
		planets[i].speed = 175 * screenWidthScalar;
	}
}

void Initialize()
{
	InitializeLayer1();
	InitializeLayer2();
}

static void UpdateLayer1()
{
	for (int i = 0; i < STARS_AMOUNT; i++)
	{
		stars[i].position.x -= static_cast<float>(stars[i].speed) * deltaTime;

		if (stars[i].position.x + stars[i].radius < 0)
			stars[i].position.x = static_cast<float>(screenWidth + stars[i].radius);
	}
}

static void UpdateLayer2()
{
	for (int i = 0; i < PLANETS_AMOUNT; i++)
	{
		planets[i].position.x -= static_cast<float>(planets[i].speed) * deltaTime;

		if (planets[i].position.x + planetsSize < 0)
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

static void DrawLayer1()
{
	for (int i = 0; i < STARS_AMOUNT; i++)
	{
		DrawCircle(static_cast<int>(stars[i].position.x), static_cast<int>(stars[i].position.y), static_cast<float>(stars[i].radius), RAYWHITE);
	}
}

static void DrawLayer2()
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
	for (int i = PLANETS_AMOUNT - 1; i >= 0; i--)
	{
		UnloadTexture(planets[i].texture);
		UnloadImage(planets[i].image);
	}
}
}
}