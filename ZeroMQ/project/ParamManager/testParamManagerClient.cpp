//
// Created by xuyanghe on 19-9-12.
//
#include <memory>
#include "Subscriber.h"
#include <cmath>

int main (int argc, char** argv) {
    std::string host =  "localhost";
    const void* paramName = "F_error";
    auto subscriber = std::make_shared<Subscriber>();
    subscriber->initSubscriber(host,paramName);

    //--------------远程修改/添加参数--------------
//    const void* paramName2 = "modifiedParam";
//    double k = 12.11;
//    subscriber->modifyParamEthernet(host,paramName2,k);
    

    //--------------开启线程循环获取数据--------------
//    subscriber->startRecv();
//    while(true);

    //--------------只获取一次数据--------------
    subscriber->recvOnce();

    while(true) {
        subscriber->recvOnce();
        usleep((__useconds_t)pow(10,6));
    }
}