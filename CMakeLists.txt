# TODO: Selection to Linux OS
cmake_minimum_required(VERSION 2.8)

project(RenderEngine)

if(UNIX)
    set(EXTERNAL_PLATFORM_DEP_INCLUDES external/SDL2-2.0.5/Ubuntu14_x86_64/include/)
    set(LINK_DIRECTORIES ${PROJECT_SOURCE_DIR}/external/SDL2-2.0.5/Ubuntu14_x86_64/lib/)
    set(SHARED_OBJECTS_DIRECTORIES ${PROJECT_SOURCE_DIR}/external/SDL2-2.0.5/Ubuntu14_x86_64/bin/)
    set(LINK_LIBRARIES SDL2 SDL2main SDL2_image GL)
else()
    set(EXTERNAL_PLATFORM_DEP_INCLUDES external/SDL2-2.0.5/WinMinGW64/include/)
    set(LINK_DIRECTORIES ${PROJECT_SOURCE_DIR}/external/SDL2-2.0.5/WinMinGW64/lib/)
    set(SHARED_OBJECTS_DIRECTORIES ${PROJECT_SOURCE_DIR}/external/SDL2-2.0.5/WinMinGW64/bin/)
    set(LINK_LIBRARIES mingw32 SDL2 SDL2main SDL2_image SDL2.dll OpenGL32)
endif()

SET(CMAKE_CXX_FLAGS " -std=c++11 -msse3 ")
#SET(CMAKE_EXE_LINKER_FLAGS  " -msse3, -march=, -mfpmath=sse")

include_directories(external/LinearMath/include/)
include_directories(${EXTERNAL_PLATFORM_DEP_INCLUDES})
include_directories(include/)


file(GLOB SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp 
    ${PROJECT_SOURCE_DIR}/src/Assets/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Components/*.cpp)

link_directories(${LINK_DIRECTORIES})
add_library(RenderEngine SHARED ${SOURCES})
target_link_libraries(RenderEngine PUBLIC ${LINK_LIBRARIES})

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

message(${SHARED_OBJECTS_DIRECTORIES})