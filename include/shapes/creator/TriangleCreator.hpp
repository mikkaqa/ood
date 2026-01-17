#pragma once

#include "Creator.hpp"
#include "../adapter/SFMLTriangleAdapter.hpp"

class TriangleCreator : public Creator
{
public:
    static TriangleCreator &GetInstance();

    std::shared_ptr<IDrawableShape> CreateShape(const std::vector<float> &params) override;

    TriangleCreator(const TriangleCreator &) = delete;
    TriangleCreator &operator=(const TriangleCreator &) = delete;

private:
    TriangleCreator() = default;

    static TriangleCreator *instance;
};