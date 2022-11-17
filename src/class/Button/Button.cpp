#include "class/Button.hpp"
#include "class/Game.hpp"
#include "class/Asset.hpp"
#include "class/Logger.hpp"
#include "class/Settings.hpp"
#include "prototypes.hpp"

Button::Button()
{
    m_shape.setFillColor(Color::White);
    m_shape.setSize(Vector2f(100, 75));
    m_onClick = &doNothingFunc;
    m_clickSound.setBuffer(Asset::SOUND_CLICK);
    m_hoverSound.setBuffer(Asset::SOUND_HOVER);
}

Button::Button(Vector2f size, Vector2f pos, Texture& texture, void (*onClick)())
{
    m_shape.setFillColor(Color::White);
    m_shape.setSize(size);
    m_shape.setTexture(&texture);
    m_shape.setTextureRect(IntRect(0, 0,
    texture.getSize().x / 3, texture.getSize().y));
    m_shape.setOrigin(getCenter(m_shape));
    m_shape.setPosition(pos);
    m_state = idle;
    m_onClick = onClick;
    m_clickSound.setBuffer(Asset::SOUND_CLICK);
    m_hoverSound.setBuffer(Asset::SOUND_HOVER);
}

void Button::setTexture(Texture* texture)
{
    m_shape.setTexture(texture);
    m_shape.setTextureRect(IntRect(0, 0,
    texture->getSize().x / 3, texture->getSize().y));
    m_shape.setOrigin(getCenter(m_shape));
}

void Button::setOnClick(void (*onClick)())
{
    m_onClick = onClick;
}

void Button::onClick()
{
    m_onClick();
}

void Button::setPos(Vector2f pos)
{
    m_shape.setPosition(pos);
}

RectangleShape& Button::getShape()
{
    return m_shape;
}

void Button::update(Vector2i mousePos)
{
    FloatRect bound = m_shape.getGlobalBounds();
    IntRect t_rect = m_shape.getTextureRect();
    Vector2u t_size = m_shape.getTexture()->getSize();
    static bool playHoverSound = true;

    if (DoMouseIntersect(mousePos, bound)) {
        if (playHoverSound) {
            playHoverSound = false;
            m_hoverSound.setVolume(Settings::SFX_VOLUME);
            modulateSound(&m_hoverSound, 1.0, 1.15);
            m_hoverSound.play();
        }
        if (m_state == 2 && !Mouse::isButtonPressed(Mouse::Left)) {
            m_clickSound.setVolume(Settings::SFX_VOLUME);
            modulateSound(&m_clickSound, 0.95, 1.05);
            m_clickSound.play();
            onClick();
            m_state = 0;
        } else if (Mouse::isButtonPressed(Mouse::Left)) {
            m_state = 2;
            t_rect.left = t_size.x / 1.5;
        }
        if (m_state == 0) {
            m_state = 1;
            t_rect.left = t_size.x / 3;
        }
    } else if (m_state != 0) {
        playHoverSound = true;
        m_state = 0;
        t_rect.left = 0;
    }
    m_shape.setTextureRect(t_rect);
    m_shape.setOrigin(getCenter(m_shape));
}
