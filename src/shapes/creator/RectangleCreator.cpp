#include "../../../include/shapes/creator/RectangleCreator.hpp"

RectangleCreator *RectangleCreator::instance = nullptr;

RectangleCreator &RectangleCreator::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new RectangleCreator();
    }
    return *instance;
}

std::shared_ptr<IDrawableShape> RectangleCreator::CreateShape(const std::vector<float> &params)
{
    if (params.size() != shapes::params_count::RECTANGLE)
    {
        return nullptr;
    }

    Point topLeft(params[0], params[1]);
    float width = params[2];
    float height = params[3];
    return std::make_shared<SFMLRectangleAdapter>(topLeft, width, height);
}