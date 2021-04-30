cmake_minimum_required(VERSION 3.10)
project(LCGE)

set(TARGET ${PROJECT_NAME} C_STANDARD 99)

set(SOURCES
    "src/window.c"
    "src/core.c"
)

set(HEADERS
    "include/LCGE/lcge.h"
    "src/core.h"
    "src/debug.h"
    "src/glerror.h"
    "src/window.h"
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE "./include")

# Tests
add_executable(window_example "tests/window.c")
target_include_directories(window_example PRIVATE "./include")
target_link_libraries(window_example PRIVATE ${PROJECT_NAME})

set(GLFW_DIR "lib/glfw")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

set(GLAD_DIR "lib/glad")
add_library(glad "${GLAD_DIR}/src/glad.c")
target_include_directories(glad PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} glad "${CMAKE_DL_LIBS}")

IF (WIN32)
	target_link_libraries(${PROJECT_NAME} opengl32)
ENDIF()