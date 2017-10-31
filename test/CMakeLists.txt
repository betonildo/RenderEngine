project(Test)

add_executable(Test main.cpp)

# RENDER ENGINE INCLUDE DIRECTORY
include_directories(${RenderEngine_SOURCE_DIR}/include)

# LINK ONLY TO RENDER ENGINE (ALL LIBRARIES LINKED TO RENDER ENGINE ARE STATICALLY LINKED)
target_link_libraries(Test RenderEngine)

# SETUP EXPORT DLL FOR WINDOWS

MESSAGE( STATUS "RenderEngine_SOURCE_DIR:         " ${RenderEngine_SOURCE_DIR})

# Copy ASSIMP dll
add_custom_command(TARGET Test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${Assimp_BINARY_DIR}/code/\$\(Configuration\)/"
    $<TARGET_FILE_DIR:Test>)

# Copy RenderEngine dll
add_custom_command(TARGET Test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${RenderEngine_BINARY_DIR}/\$\(Configuration\)/"
    $<TARGET_FILE_DIR:Test>)