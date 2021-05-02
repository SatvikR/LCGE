cmake_minimum_required(VERSION 3.10)
project(LCGE)

set(TARGET ${PROJECT_NAME} C_STANDARD 99)

set(SRC_DIR "src")
set(INCLUDE_DIR "include")

set(SOURCES
    "${SRC_DIR}/window.c"
    "${SRC_DIR}/core.c"
    "${SRC_DIR}/glerror.c"
    "${SRC_DIR}/renderer/indexbuffer.c"
    "${SRC_DIR}/renderer/shader.c"
    "${SRC_DIR}/renderer/vertexarray.c"
    "${SRC_DIR}/renderer/vertexbuffer.c"
    "${SRC_DIR}/geometry/rect.c"
    "${SRC_DIR}/geometry/math.c"
)

set(HEADERS
    "${INCLUDE_DIR}/LCGE/lcge.h"
    "${SRC_DIR}/core.h"
    "${SRC_DIR}/debug.h"
    "${SRC_DIR}/glerror.h"
    "${SRC_DIR}/window.h"
    "${SRC_DIR}/renderer/indexbuffer.h"
    "${SRC_DIR}/renderer/shader.h"
    "${SRC_DIR}/renderer/vertexarray.h"
    "${SRC_DIR}/renderer/vertexbuffer.h"
    "${SRC_DIR}/renderer/renderer.h"
    "${SRC_DIR}/geometry/rect.h"
    "${SRC_DIR}/geometry/math.h"
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

set(TEST_DIR "tests")
set(WINDOW_EXAMPLE window_example)
set(SQUARES_EXAMPLE squares_example)
set(MOVE_EXAMPLE movement_example)

# Tests
add_executable(${WINDOW_EXAMPLE} "tests/window.c")
target_include_directories(${WINDOW_EXAMPLE} PRIVATE ${INCLUDE_DIR})
target_link_libraries(${WINDOW_EXAMPLE} PRIVATE ${PROJECT_NAME})

add_executable(${SQUARES_EXAMPLE} "tests/squares.c")
target_include_directories(${SQUARES_EXAMPLE} PRIVATE "./include")
target_link_libraries(${SQUARES_EXAMPLE} PRIVATE ${PROJECT_NAME})

add_executable(${MOVE_EXAMPLE} "tests/movement.c")
target_include_directories(${MOVE_EXAMPLE} PRIVATE "./include")
target_link_libraries(${MOVE_EXAMPLE} PRIVATE ${PROJECT_NAME})

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

message("Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")