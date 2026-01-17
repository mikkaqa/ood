#pragma once

#include <fstream>
#include <unordered_map>

#include "../shapes/adapter/IDrawableShape.hpp"
#include "../shapes/creator/CircleCreator.hpp"
#include "../shapes/creator/RectangleCreator.hpp"
#include "../shapes/creator/TriangleCreator.hpp"

class ShapeParser
{
public:
    static std::vector<std::shared_ptr<IDrawableShape>> ParseFile(std::ifstream &filename);

private:
    static const std::unordered_map<std::string, Creator &> creators;
};