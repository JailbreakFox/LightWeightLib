PROJECT(ParamManager)

INCLUDE_DIRECTORIES(PubAndSub)

file(GLOB SrcFiles
        PubAndSub/*.cpp
        PubAndSub/*.h
        )

#添加thread
find_package(Threads)

add_executable(ParamManagerServer testParamManagerServer.cpp ${SrcFiles})
target_link_libraries(ParamManagerServer glog zmq ${CMAKE_THREAD_LIBS_INIT})

add_executable(ParamManagerClient testParamManagerClient.cpp ${SrcFiles})
target_link_libraries(ParamManagerClient glog zmq ${CMAKE_THREAD_LIBS_INIT})