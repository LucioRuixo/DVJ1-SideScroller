#include "gameplay.h"

#include "Elements/Gameplay/enemies.h"
#include "Elements/Gameplay/player.h"

namespace game
{
namespace gameplay
{
void Initialize()
{
	player::Initialize();
	enemies::Initialize();
}

void Update()
{
	player::Update();
	enemies::Update();
}

void Draw()
{
	player::Draw();
	enemies::Draw();
}
}
}