#pragma once

#include <memory>
#include <cmath>

#include "Point.hpp"
#include "IDrawableShape.hpp"
#include "../../Constants.hpp"

class SFMLRectangleAdapter : public IDrawableShape
{
public:
    SFMLRectangleAdapter(const Point &topLeft, float width, float height);

    float GetArea() const override;
    float GetPerimeter() const override;
    std::string GetName() const override;

    void Accept(Visitor &visitor) const override;
    std::string ToString() const override;

    std::shared_ptr<sf::Shape> GetShape() const override;

private:
    std::shared_ptr<sf::RectangleShape> m_rectangle;
    Point m_topLeft;
    float m_width;
    float m_height;
};