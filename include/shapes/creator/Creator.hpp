#pragma once

#include <memory>
#include <vector>

#include "../adapter/IDrawableShape.hpp"

class Creator
{
public:
    virtual ~Creator() = default;
    virtual std::shared_ptr<IDrawableShape> CreateShape(const std::vector<float> &params) = 0;

protected:
    Creator() = default;
};