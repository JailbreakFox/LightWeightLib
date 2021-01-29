//
// Created by xuyanghe on 19-9-12.
//

#ifndef PROJECT_SUBSCRIBER_H
#define PROJECT_SUBSCRIBER_H

#include <memory>
#include <thread>
#include "zhelpers.h"

class Subscriber{
public:
    Subscriber();
    ~Subscriber();

    void initSubscriber(std::string& host,const void* paramName);
    double recvOnce();
    void startRecv(double subscribeTime = 1);
    bool stopSubscribe();
    void modifyParamEthernet(std::string& host,const void* paramName,double& val);

private:
    void recvParam(double subscribeTime);
    bool _openSubscribe;

    zmq::context_t* _context;
    zmq::socket_t* _subscriber;
    zmq::socket_t* _paramModifier;
    std::shared_ptr<std::thread> _subscribeThread;
};


#endif //PROJECT_SUBSCRIBER_H
