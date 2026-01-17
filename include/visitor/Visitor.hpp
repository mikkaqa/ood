#pragma once

#include <string>
#include <memory>
#include <iomanip>
#include <sstream>

class SFMLCircleAdapter;
class SFMLRectangleAdapter;
class SFMLTriangleAdapter;

class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void VisitCircle(const SFMLCircleAdapter &circle) = 0;
    virtual void VisitRectangle(const SFMLRectangleAdapter &rectangle) = 0;
    virtual void VisitTriangle(const SFMLTriangleAdapter &triangle) = 0;

    std::string GetResult() const { return result; }

protected:
    std::string result;
};