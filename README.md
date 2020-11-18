# LightWeightLib
Some LightWeight Library Gather.

## 0x01 glog
Google logger

### install
```sh
## 可以直接安装依赖包，也可以源码安装
sudo apt install libgoogle-glog-dev

# 1)git clone glog installer  
git clone https://github.com/google/glog

# 2)下载依赖包  
sudo apt-get install autoconf automake libtool

# 3)build文件
cd glog
mkdir build && cd build

# 4)编译
cmake ..
make
sudo make install 

# 5)添加CmakeList.txt
find_package(glog)  
target_link_libraries(*** glog)
```

## 0x02 GTest
Google unit test

### install
```sh
# 1)安装依赖包
sudo apt install libgtest-dev

# 5)添加CmakeList.txt
find_package(GTest)  
target_link_libraries(*** ${GTEST_LIBRARIES} -lpthread -lm)
```
