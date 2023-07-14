cmake_minimum_required(VERSION 3.15.0)
project(cops-n-robbers-3d VERSION 0.1.0 LANGUAGES C CXX)

set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(external/raylib)
# add_subdirectory(external/raygui)

# find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0
# find_library(RAYGUILIB raygui PATH_SUFFIXES external/raygui)
add_library(raygui INTERFACE)
# target_sources(raygui INTERFACE raygui.h)
# find_library(MYCUSTOMLIB mycustomlib PATH_SUFFIXES mycustomlib)

set(CMAKE_C_STANDARD 11) # Requires C11 standard

# include(CTest)
# enable_testing()

add_executable(cops-n-robbers-3d main.cpp)


target_include_directories(raygui INTERFACE
    "${PROJECT_SOURCE_DIR}/external/raygui/src"
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC ${CMAKE_SOURCE_DIR}/../external/raylib/raylib/include
    PUBLIC ${CMAKE_SOURCE_DIR}/../external/raygui/src
)
target_link_directories(${PROJECT_NAME} 
    PRIVATE ${CMAKE_SOURCE_DIR}/../external/raylib/src
    PRIVATE ${CMAKE_SOURCE_DIR}/../external/raygui/src
)
target_link_libraries(${PROJECT_NAME} 
    raylib raylib
    raygui raygui
)
# target_link_libraries(${PROJECT_NAME} raygui)

# # set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# # set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# # include(CPack)

# # Checks if OSX and links appropriate frameworks (only required on MacOS)
# if (APPLE)
#     target_link_libraries(${PROJECT_NAME} "-framework IOKit")
#     target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
#     target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
# endif()