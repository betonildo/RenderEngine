# TODO: Selection to Linux OS
cmake_minimum_required(VERSION 2.8)

project(RenderEngine)

find_package(OpenGL REQUIRED)

# Compile external dependencies 
add_subdirectory (external)

add_definitions(
	-DGLEW_STATIC
)

if(UNIX)
    set(EXTERNAL_PLATFORM_DEP_INCLUDES external/SDL2-2.0.5/Ubuntu14_x86_64/include/)
    set(LINK_DIRECTORIES ${PROJECT_SOURCE_DIR}/external/SDL2-2.0.5/Ubuntu14_x86_64/lib/)
    set(SHARED_OBJECTS_DIRECTORIES ${PROJECT_SOURCE_DIR}/external/SDL2-2.0.5/Ubuntu14_x86_64/bin/)
    set(LINK_LIBRARIES SDL2 SDL2main SDL2_image GL m)
    SET(CMAKE_CXX_FLAGS " -std=c++11 -msse3 ")
else()
    set(EXTERNAL_PLATFORM_DEP_INCLUDES external/SDL2-2.0.5/WinMinGW64/include/)
    set(LINK_DIRECTORIES ${PROJECT_SOURCE_DIR}/external/SDL2-2.0.5/WinMinGW64/lib/ )
    set(SHARED_OBJECTS_DIRECTORIES ${PROJECT_SOURCE_DIR}/external/SDL2-2.0.5/WinMinGW64/bin/)
    set(LINK_LIBRARIES mingw32 SDL2 SDL2main SDL2_image SDL2.dll opengl32 gdi32 m)
    SET(CMAKE_CXX_FLAGS " -g -std=c++11 -msse3 ")
endif()

include_directories (external/glew-2.0.0/include/)
include_directories(include/Maths/include/)
include_directories(${EXTERNAL_PLATFORM_DEP_INCLUDES})
include_directories(include/)

link_directories(${LINK_DIRECTORIES})

file(GLOB SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp 
    ${PROJECT_SOURCE_DIR}/src/Assets/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Components/*.cpp)

set(ALL_LIBS
    ${OPENGL_LIBRARY}
    ${LINK_LIBRARIES}
    GLEW_200)

add_library(RenderEngine SHARED ${SOURCES})
target_link_libraries(RenderEngine PUBLIC ${ALL_LIBS})

add_executable(RenderEngine_Test test/main.cpp)
target_link_libraries(RenderEngine_Test RenderEngine)


install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION ${PROJECT_BINARY_DIR}/include/
    FILES_MATCHING PATTERN "*.h"
)

install(
    DIRECTORY ${SHARED_OBJECTS_DIRECTORIES}
    DESTINATION ${PROJECT_BINARY_DIR}/
    FILES_MATCHING PATTERN "*.dll"
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/resources/
    DESTINATION ${PROJECT_BINARY_DIR}/resources/
)

MESSAGE( STATUS "SHARED_OBJECTS_DIRECTORIES: " ${SHARED_OBJECTS_DIRECTORIES})
MESSAGE( STATUS "LINK_LIBRARIES: " ${LINK_LIBRARIES})
MESSAGE( STATUS "LINK_DIRECTORIES: " ${LINK_DIRECTORIES})
MESSAGE( STATUS "EXTERNAL_PLATFORM_DEP_INCLUDES: " ${EXTERNAL_PLATFORM_DEP_INCLUDES})
