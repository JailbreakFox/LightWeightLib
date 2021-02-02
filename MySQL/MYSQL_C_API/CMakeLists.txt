cmake_minimum_required(VERSION 3.7)
project(MySQL_TEST)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(MySQL)

include_directories(${MYSQL_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp ${MYSQL_INCLUDE_DIR})
if(MYSQL_FOUND)
    target_link_libraries(${PROJECT_NAME} ${MYSQL_LIBRARIES})
endif()
