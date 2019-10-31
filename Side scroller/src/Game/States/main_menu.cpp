#include "main_menu.h"

#include "Elements/UI/buttons.h"

namespace game
{
namespace main_menu
{
void Update()
{
	buttons::Update(buttons::play);
	buttons::Update(buttons::credits);
	buttons::Update(buttons::exit);
}

void Draw()
{
	buttons::Draw(buttons::play);
	buttons::Draw(buttons::credits);
	buttons::Draw(buttons::exit);
}
}
}