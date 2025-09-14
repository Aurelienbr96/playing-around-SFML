cmake_minimum_required(VERSION 3.16)
project(MySFMLApp)

set(CMAKE_CXX_STANDARD 17)

# Find SFML 3
find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network Window)

add_executable(MySFMLApp main.cpp
        domain/player.cpp
        domain/player.h
        domain/position.cpp
        domain/position.h
        infra/SFMLRenderer.cpp
        infra/SFMLRenderer.h
        application/sprite-library.cpp
        application/sprite-library.h
        domain/drawable-entity.cpp
        domain/drawable-entity.h
        domain/renderer.h
)

# Link SFML (modern target names)
target_link_libraries(MySFMLApp PRIVATE SFML::Graphics SFML::Audio SFML::Network SFML::Window)
