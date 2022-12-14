#include "class/ui/EText.hpp"
#include "class/Game.hpp"

EText::EText()
{
    setFont(GET_FONT(INGAME_FONT));
    setString("Empty string");
    setPosition(Vector2f(SCREEN_SIZE.x * 0.5, SCREEN_SIZE.y * 0.5));
}

EText::EText(Vector2f pos, String str)
{
    setFont(GET_FONT(INGAME_FONT));
    setString(str);
    setOrigin(getCenter(*this));
    setPosition(pos);
}
