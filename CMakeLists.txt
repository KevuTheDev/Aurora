cmake_minimum_required(VERSION 3.5)
project(Aurora)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(Aurora/vendor/glfw)

include_directories(Aurora/headers/
                    Aurora/vendor/glfw/include/
                    Aurora/vendor/glad/include/
                    Aurora/vendor/glm/
                    Aurora/vendor/stb/)


file(GLOB PROJECT_HEADERS Aurora/headers/*.hpp)
file(GLOB PROJECT_SOURCES Aurora/src/*.cpp)
file(GLOB VENDORS_SOURCES Aurora/vendor/glad/src/glad.c)
file(GLOB PROJECT_SHADERS Aurora/shaders/*.comp
                          Aurora/shaders/*.frag
                          Aurora/shaders/*.geom
                          Aurora/shaders/*.vert)
file(GLOB PROJECT_RESOURCES Aurora/resources/*)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})
source_group("Shaders" FILES ${PROJECT_SHADERS})
source_group("Resources" FILES ${PROJECT_RESOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

add_compile_definitions(STB_IMAGE_IMPLEMENTATION)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${VENDORS_SOURCES}
                               ${PROJECT_RESOURCES})

target_link_libraries(${PROJECT_NAME} glfw opengl32
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Aurora/shaders $<TARGET_FILE_DIR:${PROJECT_NAME}>
    DEPENDS ${PROJECT_SHADERS})

    add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Aurora/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
    DEPENDS ${PROJECT_RESOURCES})