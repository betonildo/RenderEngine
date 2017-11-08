cmake_minimum_required(VERSION 3.0)

project(All_Deps)

# Dependencies static
# SDL2
SET(SDL_SHARED OFF CACHE BOOL "Disabling SDL2 shared" FORCE)
SET(SDL_STATIC ON CACHE BOOL "Enabling SDL2 static" FORCE)
if (UNIX)
    add_definitions("-Wl,Bstatic -static -ldbus-1 -ldl -lm  -Wl,--no-undefined -pthread -lSDL2 -fPIC")
endif(UNIX)
# SOIL
SET(SOIL_SHARED OFF CACHE BOOL "Disabling SOIL shared" FORCE)
SET(SOIL_STATIC ON CACHE BOOL "Enabling SOIL static" FORCE)

# GLEW
SET(GLEW_SHARED OFF CACHE BOOL "Disabling GLEW shared" FORCE)
SET(GLEW_STATIC ON CACHE BOOL "Enabling GLEW static" FORCE)

# Assimp
SET(BUILD_SHARED_LIBS OFF CACHE BOOL "Shared Assimp enabled" FORCE)
SET(ENABLE_BOOST_WORKAROUND ON CACHE BOOL "Disabling Boost Dependency" FORCE)
SET(ASSIMP_BUILD_X3D_IMPORTER OFF CACHE BOOL "Dont build X3D importer. It has problems on windows" FORCE)
SET(ASSIMP_BUILD_TESTS OFF CACHE BOOL "Disabling Build Tests for Assimp (Folder excluded to reduce repository space)" FORCE)


add_subdirectory(SDL2-2.0.7)
add_subdirectory(SOIL)
add_subdirectory(assimp-4.0.1)
add_subdirectory(glew-2.1.0)
add_subdirectory(glm)
