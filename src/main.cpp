#include "../include/core/App.hpp"

int main()
{
    App app(input::INPUT_FILENAME, input::OUTPUT_FILENAME, window::WIDTH_SIZE, window::HEIGHT_SIZE, window::TITLE);
    return app.Run() ? 0 : 1;
}