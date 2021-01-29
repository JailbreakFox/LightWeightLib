//
// Created by xuyanghe on 19-9-12.
//

#ifndef PROJECT_PUBANDSUB_H
#define PROJECT_PUBANDSUB_H

#include <string>
#include <vector>
#include <memory>
#include <thread>
#include "zhelpers.h"

struct Param{
    std::string paramName;
    double val;
};

class Publisher{
public:
    Publisher();
    ~Publisher();

    bool startPublish(double publishTime = 1);  //默认设定时间1000ms
    bool stopPublish();
    bool modifyParam(std::string paramName,double& val);

private:
    void publish(double publishTime);
    void paramModifierRcev();

    bool _openPublish;
    zmq::context_t* _context;
    zmq::socket_t* _publisher;
    zmq::socket_t* _paramModifier;

    std::vector<Param> _param;
    std::shared_ptr<std::thread> _publishThread;
    std::shared_ptr<std::thread> _paramModifierThread;
};

#endif //PROJECT_PUBANDSUB_H
