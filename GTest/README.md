# GTest
Google unit test

### install
```sh
# 1)安装依赖包
sudo apt install libgtest-dev

# 5)添加CmakeList.txt
find_package(GTest)  
target_link_libraries(*** ${GTEST_LIBRARIES} -lpthread -lm)
```