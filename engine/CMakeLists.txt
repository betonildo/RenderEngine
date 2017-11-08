cmake_minimum_required(VERSION 3.0)
project(RenderEngine)

# SET C++14 STANDARD
set (CMAKE_CXX_STANDARD 14)

# ALL SOURCES FOR COMPILATION AND LINKING
file(GLOB RenderEngine_SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/device/*.cpp
    ${PROJECT_SOURCE_DIR}/src/graphics/*.cpp
    ${PROJECT_SOURCE_DIR}/src/scene/*.cpp
    ${PROJECT_SOURCE_DIR}/src/assets/*.cpp
    ${PROJECT_SOURCE_DIR}/src/components/*.cpp
)

# CREATE STATIC LIBRARY (TRY USING SHARED LIBRARY FOR TESTING)
add_library(RenderEngine SHARED ${RenderEngine_SOURCES})

# ALL DEPENDENCIES
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${SDL2_SOURCE_DIR}/include)
include_directories(${GLEW_SOURCE_DIR}/include)
include_directories(${Assimp_SOURCE_DIR}/include)
include_directories(${Assimp_BINARY_DIR}/include)
include_directories(${SOIL_SOURCE_DIR}/src)
include_directories(${glm_SOURCE_DIR})

# SETUP EXPORT DLL FOR WINDOWS
target_compile_definitions(RenderEngine PRIVATE ENGINE_EXPORTING=1)
target_compile_definitions(RenderEngine PRIVATE GLEW_STATIC=1)

# LINK LIBRARIES
set(SDL2_LIBRARIES 
    vcruntimed
    ucrtd
    SDL2-static
    SDL2main
    winmm
    imm32
    version
    gdi32
)

set(ASSIMP_LIBRARIES
    assimp
)

target_link_libraries(RenderEngine ${SDL2_LIBRARIES} SOIL ${ASSIMP_LIBRARIES} GLEW)

# GET SOURCE LOCATION OF LIBRARIES
MESSAGE( STATUS "PROJECT_SOURCE_DIR   "  ${PROJECT_SOURCE_DIR})
MESSAGE( STATUS "SDL2_SOURCE_DIR      "  ${SDL2_SOURCE_DIR})
MESSAGE( STATUS "GLEW_SOURCE_DIR      "  ${GLEW_SOURCE_DIR})
MESSAGE( STATUS "Assimp_SOURCE_DIR    "  ${Assimp_SOURCE_DIR})
MESSAGE( STATUS "Assimp_BINARY_DIR    "  ${Assimp_BINARY_DIR})
MESSAGE( STATUS "SOIL_SOURCE_DIR      "  ${SOIL_SOURCE_DIR})
MESSAGE( STATUS "glm_SOURCE_DIR       "  ${glm_SOURCE_DIR})
MESSAGE( STATUS "ASSIMP_STATIC_LIB    "  ${ASSIMP_STATIC_LIB})


# Copy ASSIMP dll
add_custom_command(TARGET RenderEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${Assimp_BINARY_DIR}/code/\$\(Configuration\)/"
    "${RenderEngine_BINARY_DIR}/exported")

# Copy RenderEngine include
add_custom_command(TARGET RenderEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${RenderEngine_SOURCE_DIR}/include/"
    "${RenderEngine_BINARY_DIR}/exported/include")

# Copy RenderEngine dll
add_custom_command(TARGET RenderEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${RenderEngine_BINARY_DIR}/\$\(Configuration\)/"
    "${RenderEngine_BINARY_DIR}/exported")

# Copy glm sources
add_custom_command(TARGET RenderEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${glm_SOURCE_DIR}/glm/"
    "${RenderEngine_BINARY_DIR}/exported/include/glm")