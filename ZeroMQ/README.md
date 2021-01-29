# ZeroMQLearning
Open TcpSocket Library

## 教程
文件夹file以及filecode为教程文档和代码

## Ubuntu16.04 zmq交叉编译环境
*1、安装zmq*
sudo apt-get install libzmq3-dev

*2、添加cmakelist*
```cmake
## i have cmake 3.5
cmake_minimum_required(VERSION 3.5)
project(test2)

## use this to globally use C++11 with in our project
set(CMAKE_CXX_STANDARD 11)

## load in pkg-config support
find_package(PkgConfig)
## use pkg-config to get hints for 0mq locations
pkg_check_modules(PC_ZeroMQ QUIET zmq)

## use the hint from above to find where 'zmq.hpp' is located
find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
        )

## use the hint from about to find the location of libzmq
find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
        )

set(SOURCE_FILES main.cpp)
add_executable(test2 ${SOURCE_FILES})
```