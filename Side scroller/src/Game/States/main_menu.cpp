#include "main_menu.h"

#include "Elements/UI/buttons.h"

namespace game
{
namespace main_menu
{
void Update()
{
	buttons::Update(buttons::play);
}

void Draw()
{
	buttons::Draw(buttons::play);
}
}
}