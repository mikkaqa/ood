#pragma once

#define _USE_MATH_DEFINES

#include <memory>
#include <cmath>
#include <string>

#include "Point.hpp"
#include "IDrawableShape.hpp"
#include "../../Constants.hpp"

class SFMLCircleAdapter : public IDrawableShape
{
public:
    SFMLCircleAdapter(const Point &center, float radius);

    float GetArea() const override;
    float GetPerimeter() const override;
    std::string GetName() const override;

    void Accept(Visitor &visitor) const override;
    std::string ToString() const override;

    std::shared_ptr<sf::Shape> GetShape() const override;

private:
    std::shared_ptr<sf::CircleShape> m_circle;
    Point m_center;
    float m_radius;
};