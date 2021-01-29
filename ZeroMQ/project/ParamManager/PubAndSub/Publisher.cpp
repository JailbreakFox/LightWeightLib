//
// Created by xuyanghe on 19-9-12.
//

#include "Publisher.h"
#include "glog/logging.h"
#include "zhelpers.h"
#include <thread>
#include "IPAndPort.h"

//TODO:添加网口修改参数的功能
//TODO:分类可修改与不可修改的参数

Publisher::Publisher() :
        _openPublish(false),
        _publisher(nullptr){
    _param.clear();
}

Publisher::~Publisher() {
    //关闭网络端口
    zmq_close (_publisher);
    zmq_term (_context);
}

bool Publisher::startPublish(double publishTime) {
    if(_param.empty()) {
        LOG(INFO) << "[-]There is no param,please modifyParam first!";
        return false;
    }

    if(_publisher || _paramModifier) {
        LOG(INFO) << "[-]Publish already begin!";
        return false;
    }
    
    //生成发布参数的网络端口
    _context = new zmq::context_t(1);
    _publisher = new zmq::socket_t(*_context,ZMQ_PUB);
    _publisher->bind("tcp://*:" + PORT_PUBANDSUB);

    //生成客户端修改参数数据的网络端口
    _paramModifier = new zmq::socket_t(*_context, ZMQ_REP);
    _paramModifier->bind("tcp://*:" + PORT_PARAMMODIFIER);

    _openPublish = true;

    //开启publish线程
    _publishThread = std::make_shared<std::thread>(&Publisher::publish,this,publishTime);
    _publishThread->detach();

    //开启paramModifier线程
    _paramModifierThread = std::make_shared<std::thread>(&Publisher::paramModifierRcev,this);
    _paramModifierThread->detach();
}

bool Publisher::stopPublish() {
    _openPublish = false;
    if(_publisher && _paramModifier) {
        zmq_close (_publisher);
        zmq_close (_paramModifier);
        zmq_term (_context);
    }
}

//程序内修改参数
bool Publisher::modifyParam(std::string paramName,double& val) {
    bool insertParam = true;
    for(auto& param_i : _param) {
        if(param_i.paramName == paramName) {
            param_i.val = val;
            insertParam = false;
            break;
        }
    }

    if(insertParam) {
        //编辑新的参数名与值
        Param newParam;
        newParam.paramName = paramName;
        newParam.val = val;
        _param.push_back(newParam);
        LOG(INFO) << "[+]Add new param : " << _param.back().paramName;
    }
    
    if(!_openPublish) {
        LOG(INFO) << "[+]Can use startPublish to start publishing!";
    }
}

void Publisher::publish(double publishTime) {
    while(_openPublish && !_param.empty()) {
        //开启publish定时器
        auto timenow = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration(publishTime);

        //发布一次
        for(auto param_i : _param) {
            s_sendmore (*_publisher, param_i.paramName);
            s_send (*_publisher, std::to_string(param_i.val));
        }
        std::this_thread::sleep_until(timenow + duration);
    }
}

void Publisher::paramModifierRcev() {
    while(_openPublish){
        zmq::message_t request;
        std::string paramName;
        std::string val;
        // 等待客户端请求
        auto recvSuccess = _paramModifier->recv(&request);
        auto* recvData((char *)request.data());
        if(recvSuccess) {
            char *recvDataList;
            recvDataList = strtok(recvData,";");
            if(recvDataList) {
                paramName = recvDataList;
            }
            recvDataList = strtok(nullptr,",");
            if(recvDataList) {
                val = recvDataList;
            }

            //modifyParam
            double valDouble = std::stod(val);
            modifyParam(paramName,valDouble);
            LOG(INFO) << "[+]modify Param :" << paramName << " , and the value is :" << valDouble;
        }

        // 做一些“处理”
        sleep(1);

        // 应答World
        std::string reply = "Received param modify command!";
        s_send(*_paramModifier,reply);
    }
}