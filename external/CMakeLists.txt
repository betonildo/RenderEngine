if(MSVC AND NOT "${MSVC_VERSION}" LESS 1400)
	add_definitions( "/MP" )
endif()


add_definitions(
	-DGLEW_STATIC
	-DSOIL_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

include_directories(
	glew-2.0.0/include/
)
### GLEW ###

set(GLEW_SOURCE
	glew-2.0.0/src/glew.c
)

set(GLEW_HEADERS
)


set(CMAKE_C_FLAGS " -g -fPIC ")

add_library( GLEW_200 STATIC
	${GLEW_SOURCE}
	${GLEW_INCLUDE}
)

target_link_libraries(GLEW_200
	${OPENGL_LIBRARY}
	${EXTRA_LIBS}
)

#SOIL
include_directories(SOIL/)

set(SOIL_SOURCES
	SOIL/image_DXT.c
	SOIL/image_helper.c
	SOIL/SOIL.c
	SOIL/stb_image_aug.c)

add_library(SOIL STATIC
	${SOIL_SOURCES}
	SOIL/)

target_link_libraries(SOIL)
