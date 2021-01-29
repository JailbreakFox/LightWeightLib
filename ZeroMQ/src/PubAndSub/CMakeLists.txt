PROJECT(PubAndSub)

INCLUDE_DIRECTORIES(include)
FILE(GLOB PubServer_file
        include/*.h
        )

## add the include directory to our compile directives
ADD_EXECUTABLE(PubServer PubServer.cpp ${ZeroMQ_INCLUDE_DIR} ${PubServer_file})
## at the 0mq library to our link directive
target_link_libraries(PubServer ${ZeroMQ_LIBRARY})

## add the include directory to our compile directives
ADD_EXECUTABLE(SubClient SubClient.cpp ${ZeroMQ_INCLUDE_DIR} ${PubServer_file})
## at the 0mq library to our link directive
target_link_libraries(SubClient ${ZeroMQ_LIBRARY})