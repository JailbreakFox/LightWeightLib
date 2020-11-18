project(GTest)

INCLUDE_DIRECTORIES(unitTest)
find_package(GTest REQUIRED)
FILE(GLOB GTest_file
        unitTest/*.cpp
        unitTest/*.h
        )

add_executable(GTest main.cpp ${GTest_file})
target_link_libraries(GTest ${GTEST_LIBRARIES} -lpthread -lm)
