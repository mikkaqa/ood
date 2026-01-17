#pragma once

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace window
{
    const unsigned int WIDTH_SIZE = 800;
    const unsigned int HEIGHT_SIZE = 500;
    const std::string TITLE = "Shapes";
}

namespace input
{
    const std::string INPUT_FILENAME = "../data/input.txt";
    const std::string OUTPUT_FILENAME = "../data/output.txt";
}

namespace output
{
    const std::string COLON = ": ";
    const std::string PERIMETER = "P=";
    const std::string AREA = "S=";
    const std::string SEPARATOR = "; ";

    const std::string RECTANGLE = "RECTANGLE";
    const std::string CIRCLE = "CIRCLE";
    const std::string TRIANGLE = "TRIANGLE";
}

namespace graphics
{
    namespace colors
    {
        const sf::Color CIRCLE_FILL = sf::Color::Green;
        const sf::Color RECTANGLE_FILL = sf::Color::Blue;
        const sf::Color TRIANGLE_FILL = sf::Color::Red;
        const sf::Color OUTLINE = sf::Color::Black;
        const sf::Color BACKGROUND = sf::Color::White;
        const sf::Color TRANSPARENT = sf::Color::Transparent;
    }

    const float OUTLINE_THICKNESS = 2.0f;
    const unsigned int FRAME_RATE_LIMIT = 60;
}

namespace parsing
{
    const char PARAM_DELIMITER = ',';
    const std::string TYPE_DELIMITER = ": ";
}

namespace format
{
    const int PRECISION = 2;
}

namespace shapes
{
    const std::string CIRCLE = "CIRCLE";
    const std::string RECTANGLE = "RECTANGLE";
    const std::string TRIANGLE = "TRIANGLE";

    namespace params_count
    {
        const int CIRCLE = 3;
        const int RECTANGLE = 4;
        const int TRIANGLE = 6;
    }

    enum class TYPE
    {
        CIRCLE = 0,
        RECTANGLE,
        TRIANGLE
    };

    const std::unordered_map<std::string, TYPE> SHAPES_MAP =
        {
            {shapes::RECTANGLE, TYPE::RECTANGLE},
            {shapes::CIRCLE, TYPE::CIRCLE},
            {shapes::TRIANGLE, TYPE::TRIANGLE}};

    inline TYPE stringToType(const std::string &typeStr)
    {
        auto it = SHAPES_MAP.find(typeStr);
        return it->second;
    }

}

namespace messages
{
    const std::string LOADING_SHAPES = "Loading shapes from file...";
    const std::string NO_SHAPES_LOADED = "No shapes loaded. Exiting.";
    const std::string LOADED_SHAPES_PREFIX = "Loaded ";
    const std::string LOADED_SHAPES_SUFFIX = " shapes.";
    const std::string STARTING_VISUALIZATION = "Starting visualization";

    const std::string ERROR_PREFIX = "Error: ";
    const std::string CANNOT_OPEN_INPUT_FILE = "Cannot open input file: ";
    const std::string CANNOT_OPEN_OUTPUT_FILE = "Cannot open output file: ";
    const std::string CANVAS_INITIALIZATION_FAILED = "Failed to initialize canvas (SFML window).";
    const std::string FILES_CLOSED_UNEXPECTEDLY = "Input or output files are closed unexpectedly.";

}
