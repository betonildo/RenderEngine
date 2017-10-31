if(MSVC AND NOT "${MSVC_VERSION}" LESS 1400)
	add_definitions( "/MP" )
endif()

cmake_minimum_required(VERSION 3.0)
project(GLEW)

if (GLEW_STATIC)
	add_definitions(-DGLEW_STATIC)
endif()

### GLEW ###

set(GLEW_SOURCE
	${PROJECT_SOURCE_DIR}/src/glew.c
)

set(GLEW_HEADERS
	${PROJECT_SOURCE_DIR}/include/GL/glew.h
)

include_directories(${PROJECT_SOURCE_DIR}/include/)

if (GLEW_STATIC)
	add_library(GLEW STATIC ${GLEW_SOURCE} ${GLEW_INCLUDE})
endif()

if (GLEW_SHARED)
	add_library(GLEW SHARED ${GLEW_SOURCE} ${GLEW_INCLUDE})
endif()



target_link_libraries(GLEW
	${OPENGL_LIBRARY}
	${EXTRA_LIBS}
)

