CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(GLAD_PRO)

set( CMAKE_CXX_FLAGS "-std=c++11" )

FILE(GLOB_RECURSE glad_file glad/*.c glad/*.h)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp ${glad_file})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} glfw OpenGL::GL)
