#include "../../../include/shapes/creator/TriangleCreator.hpp"

TriangleCreator *TriangleCreator::instance = nullptr;

TriangleCreator &TriangleCreator::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new TriangleCreator();
    }
    return *instance;
}

std::shared_ptr<IDrawableShape> TriangleCreator::CreateShape(const std::vector<float> &params)
{
    if (params.size() != shapes::params_count::TRIANGLE)
    {
        return nullptr;
    }

    Point p1(params[0], params[1]);
    Point p2(params[2], params[3]);
    Point p3(params[4], params[5]);
    return std::make_shared<SFMLTriangleAdapter>(p1, p2, p3);
}