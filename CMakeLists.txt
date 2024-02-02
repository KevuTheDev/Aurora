cmake_minimum_required(VERSION 3.5)
project(Aurora)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(Aurora/vendor/glfw)

include_directories(Aurora/headers/
                    Aurora/vendor/glfw/include/
                    Aurora/vendor/glad/include/)


file(GLOB PROJECT_HEADERS Aurora/headers/*.hpp)
file(GLOB PROJECT_SOURCES Aurora/src/*.cpp)
file(GLOB VENDORS_SOURCES Aurora/vendor/glad/src/glad.c)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
			       ${VENDORS_SOURCES})

target_link_libraries(${PROJECT_NAME} glfw opengl32
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})