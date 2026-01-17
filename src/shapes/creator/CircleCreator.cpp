#include "../../../include/shapes/creator/CircleCreator.hpp"

CircleCreator *CircleCreator::instance = nullptr;

CircleCreator &CircleCreator::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new CircleCreator();
    }
    return *instance;
}

std::shared_ptr<IDrawableShape> CircleCreator::CreateShape(const std::vector<float> &params)
{
    if (params.size() != shapes::params_count::CIRCLE)
    {
        return nullptr;
    }

    Point center(params[0], params[1]);
    float radius = params[2];
    return std::make_shared<SFMLCircleAdapter>(center, radius);
}