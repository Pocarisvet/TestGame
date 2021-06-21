include_directories(include)

set(	SOURCE_FILES
	src/glad.c
)

set(	HEADER_FILES
	include/glad/glad.h
	include/KHR/khrplatform.h
)

add_library(glad STATIC ${SOURCE_FILES} ${HEADER_FILES})