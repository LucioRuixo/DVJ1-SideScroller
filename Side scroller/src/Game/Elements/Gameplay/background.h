#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "raylib.h"

namespace game
{
namespace background
{
extern const int PLANETS_AMOUNT;
extern const int PLANETS_SIZE;
extern const int STARS_AMOUNT;
extern const int STARS_MIN_RADIUS;
extern const int STARS_MAX_RADIUS;

extern const float PLANETS_SPEED;
extern const float STARS_SPEED;

struct Planet
{
	Color color;
	Image image;
	Texture2D texture;
	Vector2 position;
};

struct Star
{
	Vector2 position;

	float radius;
};

extern Planet planets[];
extern Star stars[];

void InitializeLayer1();
void InitializeLayer2();
void Initialize();
void UpdateLayer1();
void UpdateLayer2();
void Update();
void DrawLayer1();
void DrawLayer2();
void Draw();
void Close();
}
}

#endif