//
// Created by xuyanghe on 19-9-12.
//

#include "Subscriber.h"
#include "glog/logging.h"
#include "zhelpers.h"
#include <thread>
#include "IPAndPort.h"

Subscriber::Subscriber():
        _openSubscribe(false),
        _subscriber(nullptr){
}

Subscriber::~Subscriber(){
    //关闭网络端口
    zmq_close(_subscriber);
    zmq_term(_context);
}

void Subscriber::initSubscriber(std::string& host,const void* paramName){
    if(!_subscriber) {
        //生成订阅参数的网络端口
        _context = new zmq::context_t(1);
        _subscriber = new zmq::socket_t(*_context,ZMQ_SUB);
        _subscriber->connect("tcp://" + host + ":" + PORT_PUBANDSUB);
    }else {
        LOG(INFO) << "[-]subscriber already exist!";
    }
    _subscriber->setsockopt( ZMQ_SUBSCRIBE, paramName, 1);
}

void Subscriber::modifyParamEthernet(std::string& host,const void* paramName,double& val) {
    _paramModifier = new zmq::socket_t(*_context,ZMQ_REQ);
    _paramModifier->connect("tcp://"+ host + ":" + PORT_PARAMMODIFIER);
    
    std::string param = static_cast<const char*>(paramName);
    std::string paramAndVal = param + ";" + std::to_string(val);
    s_send (*_paramModifier, paramAndVal);

    //  Get the reply.
    zmq::message_t reply;
    auto recvSuccess = _paramModifier->recv(&reply);
    auto* recvData((char *)reply.data());
    if(recvSuccess) {
        LOG(INFO) << recvData;
    }
    zmq_close(_paramModifier);
}

void Subscriber::startRecv(double subscribeTime) {
    if(!_subscriber) {
        LOG(INFO) << "[-]Please initSubscriber first!";
        return;
    }
    //开启subscribe定时器
    _openSubscribe = true;

    //开启publish线程
    _subscribeThread = std::make_shared<std::thread>(&Subscriber::recvParam,this,subscribeTime);
    _subscribeThread->detach();
}

double Subscriber::recvOnce() {
    if(!_subscriber) {
        LOG(INFO) << "[-]Please initSubscriber first!";
        return false;
    }

    //接收一次信息
    std::string address = s_recv (*_subscriber);
    std::string contents = s_recv (*_subscriber);
    double recvVal = std::stod(contents);

    LOG(INFO) << "[" << address << "] " << contents;
    return recvVal;
}

bool Subscriber::stopSubscribe() {
    _openSubscribe = false;
    if(_subscriber) {
        //关闭网络端口
        zmq_close (_subscriber);
        zmq_term (_context);
    }
}

void Subscriber::recvParam(double subscribeTime) {
    while(_openSubscribe) {
        //开启publish定时器
        auto timenow = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration(subscribeTime);

        //接收一次信息
        std::string address = s_recv (*_subscriber);
        std::string contents = s_recv (*_subscriber);

        LOG(INFO) << "[" << address << "] " << contents;

        std::this_thread::sleep_until(timenow + duration);
    }
}