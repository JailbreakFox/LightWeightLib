# LightWeightLib
Some LightWeight Library Gather.

## glog
Google logger

### install
```sh
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
find_package(glog REQUIRED)  
target_link_libraries(*** glog)
```
