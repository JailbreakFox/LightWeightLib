//
// Created by xuyanghe on 19-9-12.
//
#include <memory>
#include "Publisher.h"
#include <thread>
#include <cmath>

int main (int argc, char** argv) {
    auto publisher = std::make_shared<Publisher>();
    std::string paramName = "F_error";
    double val = 1.11;
    double delta = 0.01;
    publisher->modifyParam(paramName,val);
    publisher->startPublish();

    while (true) {
        publisher->modifyParam(paramName,val);
        val = val + delta;
        usleep((__useconds_t)pow(10,6));
    }
}