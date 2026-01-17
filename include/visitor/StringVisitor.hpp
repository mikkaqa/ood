#pragma once

#include "Visitor.hpp"
#include "../Constants.hpp"

class StringVisitor : public Visitor
{
public:
    void VisitCircle(const SFMLCircleAdapter &circle) override;
    void VisitRectangle(const SFMLRectangleAdapter &rectangle) override;
    void VisitTriangle(const SFMLTriangleAdapter &triangle) override;
};