project(Test)

add_executable(Test main.cpp)

#TODO: ONLY USE DEPENDENCIES WITHIN SOURCE FILES TO REDUCE THE EXTERNAL DEPENDENCIES TO LIBRARY USAGE

# Add /lib1 and /lib2 to #include search path
include_directories(${RenderEngine_SOURCE_DIR}/include)

# Specify app's dependency on lib2.
# lib2's dependency on lib1 is automatically added.
target_link_libraries(Test RenderEngine)

MESSAGE( STATUS "RenderEngine_SOURCE_DIR:         " ${RenderEngine_SOURCE_DIR})

