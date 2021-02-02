cmake_minimum_required(VERSION 3.7)
project(MySQL_TEST)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmysqlcppconn")

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} main.cpp)
