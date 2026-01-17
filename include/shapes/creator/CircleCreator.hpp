#pragma once

#include "Creator.hpp"
#include "../adapter/SFMLCircleAdapter.hpp"

class CircleCreator : public Creator
{
public:
    static CircleCreator &GetInstance();

    std::shared_ptr<IDrawableShape> CreateShape(const std::vector<float> &params) override;

    CircleCreator(const CircleCreator &) = delete;
    CircleCreator &operator=(const CircleCreator &) = delete;

private:
    CircleCreator() = default;

    static CircleCreator *instance;
};