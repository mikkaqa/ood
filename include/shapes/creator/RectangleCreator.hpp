#pragma once

#include "Creator.hpp"
#include "../adapter/SFMLRectangleAdapter.hpp"

class RectangleCreator : public Creator
{
public:
    static RectangleCreator &GetInstance();

    std::shared_ptr<IDrawableShape> CreateShape(const std::vector<float> &params) override;

    RectangleCreator(const RectangleCreator &) = delete;
    RectangleCreator &operator=(const RectangleCreator &) = delete;

private:
    RectangleCreator() = default;

    static RectangleCreator *instance;
};