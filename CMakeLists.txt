cmake_minimum_required(VERSION 3.5)

project(rtype_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2 COMPONENTS audio graphics window system)

add_executable(rtype
    src/AEngine.cpp
    src/AnimatedSprite.cpp
    src/Bullet.cpp
    src/Engine.cpp
    src/Entities.cpp
    src/main.cpp
    src/Parallax.cpp
    src/Player.cpp
)

target_include_directories(rtype PUBLIC
    ${SFML_INCLUDE_DIR}
    include
)

target_link_libraries(rtype sfml-audio sfml-graphics sfml-window sfml-system)
