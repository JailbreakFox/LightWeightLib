PROJECT(helloworld)

## add the include directory to our compile directives
ADD_EXECUTABLE(hwServer HWServer.cpp ${ZeroMQ_INCLUDE_DIR})
## at the 0mq library to our link directive
target_link_libraries(hwServer ${ZeroMQ_LIBRARY})

## add the include directory to our compile directives
ADD_EXECUTABLE(hwClient HWClient.cpp ${ZeroMQ_INCLUDE_DIR})
## at the 0mq library to our link directive
target_link_libraries(hwClient ${ZeroMQ_LIBRARY})