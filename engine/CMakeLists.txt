cmake_minimum_required(VERSION 3.0)
project(RenderEngine)

# SET C++11 STANDARD
set (CMAKE_CXX_STANDARD 11)

# ALL SOURCES FOR COMPILATION AND LINKING
file(GLOB RenderEngine_SOURCES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Assets/*.cpp
    ${PROJECT_SOURCE_DIR}/src/Components/*.cpp
)

# CREATE STATIC LIBRARY (TRY USING SHARED LIBRARY FOR TESTING)
add_library(RenderEngine STATIC ${RenderEngine_SOURCES})

# ALL DEPENDENCIES
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${SDL2_SOURCE_DIR}/include)
include_directories(${GLEW_SOURCE_DIR}/include)
include_directories(${assimp_SOURCE_DIR}/code)
include_directories(${SOIL_SOURCE_DIR}/src)
include_directories(${glm_SOURCE_DIR}/src)

# LINK LIBRARIES
target_link_libraries(RenderEngine SDL2 SOIL assimp GLEW glm)

# GET SOURCE LOCATION OF LIBRARIES
MESSAGE( STATUS "${PROJECT_SOURCE_DIR}" ${PROJECT_SOURCE_DIR})
MESSAGE( STATUS "${SDL2_SOURCE_DIR}"    ${SDL2_SOURCE_DIR})
MESSAGE( STATUS "${GLEW_SOURCE_DIR}"    ${GLEW_SOURCE_DIR})
MESSAGE( STATUS "${assimp_SOURCE_DIR}"  ${assimp_SOURCE_DIR})
MESSAGE( STATUS "${SOIL_SOURCE_DIR}"    ${SOIL_SOURCE_DIR})
MESSAGE( STATUS "${glm_SOURCE_DIR}"    ${glm_SOURCE_DIR})