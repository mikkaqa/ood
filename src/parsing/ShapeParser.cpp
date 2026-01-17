#include <sstream>
#include <iomanip>

#include "../../include/parsing/ShapeParser.hpp"

std::vector<std::shared_ptr<IDrawableShape>> ShapeParser::ParseFile(std::ifstream &file)
{
    std::vector<std::shared_ptr<IDrawableShape>> shapes;

    std::string line;

    while (std::getline(file, line))
    {
        size_t colonPos = line.find(parsing::TYPE_DELIMITER);

        if (colonPos == std::string::npos)
        {
            continue;
        }

        std::string typeStr = line.substr(0, colonPos);

        std::string paramsStr = line.substr(colonPos + parsing::TYPE_DELIMITER.length());

        std::stringstream ss(paramsStr);
        std::vector<float> params;
        float value;
        char comma;

        while (ss >> value)
        {
            params.push_back(value);
            if (!(ss >> comma))
            {
                break;
            }
        }

        shapes::TYPE type = shapes::stringToType(typeStr);

        switch (type)
        {
        case shapes::TYPE::CIRCLE:

            if (params.size() == shapes::params_count::CIRCLE)
            {
                shapes.push_back(CircleCreator::GetInstance().CreateShape(params));
            }

        case shapes::TYPE::RECTANGLE:
            if (params.size() == shapes::params_count::RECTANGLE)
            {
                shapes.push_back(RectangleCreator::GetInstance().CreateShape(params));
            }

        case shapes::TYPE::TRIANGLE:
            if (params.size() == shapes::params_count::TRIANGLE)
            {
                shapes.push_back(TriangleCreator::GetInstance().CreateShape(params));
            }
        }
    }

    return shapes;
}