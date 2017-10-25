cmake_minimum_required(VERSION 3.0)

project(All_Deps)

SET(ASSIMP_BUILD_TESTS OFF CACHE BOOL "Disabling Build Tests for Assimp (Folder excluded to reduce repository space)" FORCE)

add_subdirectory(SDL2-2.0.7)
add_subdirectory(SOIL)
add_subdirectory(assimp-4.0.1)
add_subdirectory(glew-2.1.0)
add_subdirectory(glm)

