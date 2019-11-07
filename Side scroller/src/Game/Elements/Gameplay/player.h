#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace game
{
namespace player
{
struct Bullet
{
	Image images[2];
	Rectangle rectangle;
	Texture2D textures[2];
};

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
extern Bullet bullets[];

void Initialize();
void Update();
void Draw();
void Close();
}
}

#endif