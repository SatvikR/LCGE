cmake_minimum_required(VERSION 3.10)
project(LCGE)

set(TARGET ${PROJECT_NAME} C_STANDARD 99)

set(SRC_DIR "src")
set(INCLUDE_DIR "include")

set(SOURCES
    "${SRC_DIR}/window.c"
    "${SRC_DIR}/clock.c"
    "${SRC_DIR}/core.c"
    "${SRC_DIR}/input.c"
    "${SRC_DIR}/stbi.c"
    "${SRC_DIR}/stbtt.c"
    "${SRC_DIR}/glerror.c"
    "${SRC_DIR}/renderer/indexbuffer.c"
    "${SRC_DIR}/renderer/shader.c"
    "${SRC_DIR}/renderer/vertexarray.c"
    "${SRC_DIR}/renderer/vertexbuffer.c"
    "${SRC_DIR}/renderer/texture.c"
    "${SRC_DIR}/renderer/ttftexture.c"
    "${SRC_DIR}/geometry/rect.c"
    "${SRC_DIR}/geometry/image.c"
    "${SRC_DIR}/geometry/math.c"
)

set(HEADERS
    "${INCLUDE_DIR}/LCGE/lcge.h"
    "${SRC_DIR}/core.h"
    "${SRC_DIR}/clock.h"
    "${SRC_DIR}/input.h"
    "${SRC_DIR}/debug.h"
    "${SRC_DIR}/glerror.h"
    "${SRC_DIR}/window.h"
    "${SRC_DIR}/renderer/indexbuffer.h"
    "${SRC_DIR}/renderer/shader.h"
    "${SRC_DIR}/renderer/vertexarray.h"
    "${SRC_DIR}/renderer/vertexbuffer.h"
    "${SRC_DIR}/renderer/renderer.h"
    "${SRC_DIR}/renderer/texture.h"
    "${SRC_DIR}/renderer/ttftexture.h"
    "${SRC_DIR}/geometry/rect.h"
    "${SRC_DIR}/geometry/image.h"
    "${SRC_DIR}/geometry/math.h"
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

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

if (NOT CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DNDEBUG)
endif()

# For Mingw and GCC builds ONLY
# for MSVC use -A Win32
if (BUILD_32)
        set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS
"-m32" LINK_FLAGS "-m32")
        set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS
"-m32" LINK_FLAGS "-m32")
         MESSAGE(STATUS "Excluding 64bit library paths from search.")
         set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS OFF)
elseif (BUILD_64)
        set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS
"-m64" LINK_FLAGS "-m64")
else()

set(TEST_DIR "tests")
set(WINDOW_EXAMPLE window_example)
set(SQUARES_EXAMPLE squares_example)
set(MOVE_EXAMPLE movement_example)
set(IMAGE_EXAMPLE image_example)
set(INPUT_EXAMPLE input_example)
set(TRANSFORM_EXAMPLE transform_example)
set(NINJASTAR_EXAMPLE ninjastar_example)

# Tests
add_executable(${WINDOW_EXAMPLE} "${TEST_DIR}/window.c")
target_include_directories(${WINDOW_EXAMPLE} PUBLIC ${INCLUDE_DIR})
target_link_libraries(${WINDOW_EXAMPLE} PUBLIC ${PROJECT_NAME})

add_executable(${SQUARES_EXAMPLE} "${TEST_DIR}/squares.c")
target_include_directories(${SQUARES_EXAMPLE} PUBLIC "./include")
target_link_libraries(${SQUARES_EXAMPLE} PUBLIC ${PROJECT_NAME})

add_executable(${MOVE_EXAMPLE} "${TEST_DIR}/movement.c")
target_include_directories(${MOVE_EXAMPLE} PUBLIC "./include")
target_link_libraries(${MOVE_EXAMPLE} PUBLIC ${PROJECT_NAME})

add_executable(${IMAGE_EXAMPLE} "${TEST_DIR}/image.c")
target_include_directories(${IMAGE_EXAMPLE} PUBLIC "./include")
target_link_libraries(${IMAGE_EXAMPLE} PUBLIC ${PROJECT_NAME})

add_executable(${INPUT_EXAMPLE} "${TEST_DIR}/input.c")
target_include_directories(${INPUT_EXAMPLE} PUBLIC "./include")
target_link_libraries(${INPUT_EXAMPLE} PUBLIC ${PROJECT_NAME})

add_executable(${TRANSFORM_EXAMPLE} "${TEST_DIR}/transform.c")
target_include_directories(${TRANSFORM_EXAMPLE} PUBLIC "./include")
target_link_libraries(${TRANSFORM_EXAMPLE} PUBLIC ${PROJECT_NAME})

add_executable(${NINJASTAR_EXAMPLE} "${TEST_DIR}/ninjastar.c")
target_include_directories(${NINJASTAR_EXAMPLE} PUBLIC "./include")
target_link_libraries(${NINJASTAR_EXAMPLE} PUBLIC ${PROJECT_NAME})

endif()

set(STB_DIR "lib/stb")
target_include_directories(${PROJECT_NAME} PRIVATE ${STB_DIR})

IF (WIN32)
	target_link_libraries(${PROJECT_NAME} opengl32)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
ENDIF()

message("Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")