if(MSVC AND NOT "${MSVC_VERSION}" LESS 1400)
	add_definitions( "/MP" )
endif()

cmake_minimum_required(VERSION 3.0)
project(GLEW)

add_definitions(
	-DGLEW_STATIC
)

### GLEW ###

set(GLEW_SOURCE
	${PROJECT_SOURCE_DIR}/src/glew.c
)

set(GLEW_HEADERS
	${PROJECT_SOURCE_DIR}/include/GL/glew.h
)

include_directories(${PROJECT_SOURCE_DIR}/include/)

add_library(GLEW STATIC
	${GLEW_SOURCE}
	${GLEW_INCLUDE}
)

target_link_libraries(GLEW
	${OPENGL_LIBRARY}
	${EXTRA_LIBS}
)

