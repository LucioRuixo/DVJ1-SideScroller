#include "gameplay.h"

#include "Elements/Gameplay/player.h"

namespace game
{
namespace gameplay
{
void Initialize()
{
	player::Initialize();
}

void Update()
{
	player::Update();
}

void Draw()
{
	player::Draw();
}
}
}