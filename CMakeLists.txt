cmake_minimum_required(VERSION 3.16)
project(MySFMLProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML 3
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

# Create executable
add_executable(MySFMLApp main.cpp
        collisions.cpp
        collisions.h
        report.h
        "timeTracker .h")

# Link SFML
target_link_libraries(MySFMLApp
        SFML::Graphics
        SFML::Window
        SFML::System
)