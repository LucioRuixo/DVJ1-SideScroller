#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "raylib.h"

namespace game
{
namespace background
{
struct Planet
{
	Color color;
	Image image;
	Texture2D texture;
	Vector2 position;

	int speed;
};

struct Star
{
	Vector2 position;

	int radius;
	int speed;
};

extern Planet planets[];
extern Star stars[];

void Initialize();
void Update();
void Draw();
void Close();
}
}

#endif