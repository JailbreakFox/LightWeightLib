PROJECT(Glog)

find_package(glog REQUIRED)
add_executable(Glog Glog.cpp)
target_link_libraries(Glog glog)