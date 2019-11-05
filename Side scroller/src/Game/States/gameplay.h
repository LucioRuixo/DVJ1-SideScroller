#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

namespace game
{
namespace gameplay
{
extern Music music;

void Initialize();
void Update();
void Draw();
void Close();
}
}

#endif