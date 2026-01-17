#include <iomanip>
#include <sstream>

#include "../../../include/shapes/adapter/SFMLTriangleAdapter.hpp"
#include "../../../include/visitor/StringVisitor.hpp"

SFMLTriangleAdapter::SFMLTriangleAdapter(const Point &p1, const Point &p2, const Point &p3)
    : m_p1(p1), m_p2(p2), m_p3(p3)
{
    m_triangle = std::make_shared<sf::ConvexShape>(3);
    m_triangle->setPoint(0, sf::Vector2f(p1.GetX(), p1.GetY()));
    m_triangle->setPoint(1, sf::Vector2f(p2.GetX(), p2.GetY()));
    m_triangle->setPoint(2, sf::Vector2f(p3.GetX(), p3.GetY()));
    m_triangle->setFillColor(graphics::colors::TRIANGLE_FILL);
    m_triangle->setOutlineColor(graphics::colors::OUTLINE);
    m_triangle->setOutlineThickness(graphics::OUTLINE_THICKNESS);
}

float SFMLTriangleAdapter::GetArea() const
{
    float a = m_p1.Distance(m_p2);
    float b = m_p2.Distance(m_p3);
    float c = m_p3.Distance(m_p1);
    float p = (a + b + c) / 2.0f;

    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

float SFMLTriangleAdapter::GetPerimeter() const
{
    return m_p1.Distance(m_p2) + m_p2.Distance(m_p3) + m_p3.Distance(m_p1);
}

std::string SFMLTriangleAdapter::GetName() const
{
    return shapes::TRIANGLE;
}

void SFMLTriangleAdapter::Accept(Visitor &visitor) const
{
    visitor.VisitTriangle(*this);
}

std::string SFMLTriangleAdapter::ToString() const
{
    StringVisitor visitor;
    Accept(visitor);
    return visitor.GetResult();
}

std::shared_ptr<sf::Shape> SFMLTriangleAdapter::GetShape() const
{
    return m_triangle;
}