#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace game
{
namespace player
{
extern const int WIDTH;
extern const int HEIGHT;
extern const int HORIZONTAL_SPEED;
extern const int VERTICAL_SPEED;

struct Player
{
	Image images[2];
	Rectangle rectangle;
	Texture2D currentTexture;
	Texture2D textures[2];

	int horizontalSpeed;
	int verticalSpeed;
};

extern Player player;

void Initialize();
void Update();
void Draw();
void Close();
}
}

#endif