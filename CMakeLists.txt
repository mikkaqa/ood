cmake_minimum_required(VERSION 3.15)
project(OOD)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOD  
    src/main.cpp
    src/core/App.cpp
    src/core/Canvas.cpp
    src/parsing/ShapeParser.cpp
    src/shapes/adapter/Point.cpp
    src/shapes/adapter/SFMLCircleAdapter.cpp
    src/shapes/adapter/SFMLTriangleAdapter.cpp
    src/shapes/adapter/SFMLRectangleAdapter.cpp
    src/shapes/creator/CircleCreator.cpp
    src/shapes/creator/RectangleCreator.cpp
    src/shapes/creator/TriangleCreator.cpp
    src/visitor/StringVisitor.cpp
)

configure_file(data/input.txt ${CMAKE_CURRENT_BINARY_DIR}/data/input.txt COPYONLY)
configure_file(data/output.txt ${CMAKE_CURRENT_BINARY_DIR}/data/output.txt COPYONLY)

target_compile_definitions(OOD PRIVATE SFML_STATIC)

target_include_directories(OOD PRIVATE 
    "C:/Users/mrlur/Documents/study/libraries/SFML-3.0.2/include"
)

target_link_directories(OOD PRIVATE
    "C:/Users/mrlur/Documents/study/libraries/SFML-3.0.2/lib"
)

target_link_libraries(OOD
    sfml-graphics-s
    sfml-window-s
    sfml-system-s
    opengl32
    freetype
    winmm
    gdi32
)