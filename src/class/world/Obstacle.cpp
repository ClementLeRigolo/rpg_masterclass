#include "class/world/Obstacle.hpp"

Obstacle::Obstacle(Texture* texture, Vector2f pos, Vector2f size)
{
    m_shape.setSize(size);
    m_shape.setTextureRect(IntRect(0, 0, size.x, size.y));
    m_shape.setTexture(texture);
    m_shape.setOrigin(getCenter(m_shape));
    m_shape.setPosition(pos);
    m_shape.setTextureRect(IntRect((-m_shape.getSize().x / 2.0) + m_shape.getPosition().x,
    (-m_shape.getSize().y / 2.0) + m_shape.getPosition().y, m_shape.getSize().x, m_shape.getSize().y));
}

Collider& Obstacle::getCollider()
{
    return m_shape;
}

RectangleShape& Obstacle::getShape()
{
    return m_shape;
}
