cmake_minimum_required(VERSION 3.6)
project(gah)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/inc)

set(SOURCE_FILES
        src/GameWorld.cpp
        src/main.cpp
        src/TestEntity.cpp
        src/TestMoustachioEntity.cpp)

add_executable(gah ${SOURCE_FILES})
target_link_libraries(gah ${SDL2_LIBRARY}
                          ${SDL2_IMAGE_LIBRARIES}
                          ${SDL2_TTF_LIBRARIES})