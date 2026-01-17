#include <iomanip>
#include <sstream>

#include "../../../include/shapes/adapter/SFMLCircleAdapter.hpp"
#include "../../../include/visitor/StringVisitor.hpp"

SFMLCircleAdapter::SFMLCircleAdapter(const Point &center, float radius)
    : m_center(center), m_radius(radius)
{
    m_circle = std::make_shared<sf::CircleShape>(radius);
    m_circle->setPosition(
        {m_center.GetX() - m_radius,
         m_center.GetY() - m_radius});

    m_circle->setFillColor(graphics::colors::CIRCLE_FILL);
    m_circle->setOutlineColor(graphics::colors::OUTLINE);
    m_circle->setOutlineThickness(graphics::OUTLINE_THICKNESS);
}

float SFMLCircleAdapter::GetArea() const
{
    return M_PI * m_radius * m_radius;
}

float SFMLCircleAdapter::GetPerimeter() const
{
    return 2 * M_PI * m_radius;
}

std::string SFMLCircleAdapter::GetName() const
{
    return shapes::CIRCLE;
}

void SFMLCircleAdapter::Accept(Visitor &visitor) const
{
    visitor.VisitCircle(*this);
}

std::string SFMLCircleAdapter::ToString() const
{
    StringVisitor visitor;
    Accept(visitor);
    return visitor.GetResult();
}

std::shared_ptr<sf::Shape> SFMLCircleAdapter::GetShape() const
{
    return m_circle;
}