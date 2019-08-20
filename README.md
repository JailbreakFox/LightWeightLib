# LightWeightLib
Some LightWeight Library Gather.

## glog
Google logger

### 1.install
1)research glog installer  
sudo apt-cache search glog

2)install  
sudo apt install libgoogle-glog-dev

3)add CmakeList.txt
find_package(glog REQUIRED)  
target_link_libraries(*** glog)