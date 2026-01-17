#include "../../include/visitor/StringVisitor.hpp"
#include "../../include/shapes/adapter/SFMLCircleAdapter.hpp"
#include "../../include/shapes/adapter/SFMLRectangleAdapter.hpp"
#include "../../include/shapes/adapter/SFMLTriangleAdapter.hpp"

void StringVisitor::VisitCircle(const SFMLCircleAdapter &circle)
{
    std::ostringstream oss;
    oss << output::CIRCLE << output::COLON << output::PERIMETER
        << std::fixed << std::setprecision(format::PRECISION) << circle.GetPerimeter()
        << output::SEPARATOR << output::AREA
        << std::fixed << std::setprecision(format::PRECISION) << circle.GetArea();
    result = oss.str();
}

void StringVisitor::VisitRectangle(const SFMLRectangleAdapter &rectangle)
{
    std::ostringstream oss;
    oss << output::RECTANGLE << output::COLON << output::PERIMETER
        << std::fixed << std::setprecision(format::PRECISION) << rectangle.GetPerimeter()
        << output::SEPARATOR << output::AREA
        << std::fixed << std::setprecision(format::PRECISION) << rectangle.GetArea();
    result = oss.str();
}

void StringVisitor::VisitTriangle(const SFMLTriangleAdapter &triangle)
{
    std::ostringstream oss;
    oss << output::TRIANGLE << output::COLON << output::PERIMETER
        << std::fixed << std::setprecision(format::PRECISION) << triangle.GetPerimeter()
        << output::SEPARATOR << output::AREA
        << std::fixed << std::setprecision(format::PRECISION) << triangle.GetArea();
    result = oss.str();
}