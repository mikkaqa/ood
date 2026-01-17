#include <iomanip>
#include <sstream>

#include "../../../include/shapes/adapter/SFMLRectangleAdapter.hpp"
#include "../../../include/visitor/StringVisitor.hpp"

SFMLRectangleAdapter::SFMLRectangleAdapter(const Point &topLeft, float width, float height)
    : m_topLeft(topLeft), m_width(width), m_height(height)
{
    m_rectangle = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    m_rectangle->setPosition({topLeft.GetX(), topLeft.GetY()});
    m_rectangle->setFillColor(graphics::colors::RECTANGLE_FILL);
    m_rectangle->setOutlineColor(graphics::colors::OUTLINE);
    m_rectangle->setOutlineThickness(graphics::OUTLINE_THICKNESS);
}

float SFMLRectangleAdapter::GetArea() const
{
    return m_width * m_height;
}

float SFMLRectangleAdapter::GetPerimeter() const
{
    return 2 * (m_width + m_height);
}

std::string SFMLRectangleAdapter::GetName() const
{
    return shapes::RECTANGLE;
}

void SFMLRectangleAdapter::Accept(Visitor &visitor) const
{
    visitor.VisitRectangle(*this);
}

std::string SFMLRectangleAdapter::ToString() const
{
    StringVisitor visitor;
    Accept(visitor);
    return visitor.GetResult();
}

std::shared_ptr<sf::Shape> SFMLRectangleAdapter::GetShape() const
{
    return m_rectangle;
}