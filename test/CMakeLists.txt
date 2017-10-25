project(Test)

add_executable(Test main.cpp)

# RENDER ENGINE INCLUDE DIRECTORY
include_directories(${RenderEngine_SOURCE_DIR}/include)

# LINK ONLY TO RENDER ENGINE (ALL LIBRARIES LINKED TO RENDER ENGINE ARE STATICALLY LINKED)
target_link_libraries(Test RenderEngine)

MESSAGE( STATUS "RenderEngine_SOURCE_DIR:         " ${RenderEngine_SOURCE_DIR})

