#include "glog/logging.h"

int main(int argc, char** argv) {
    //初始化
    google::InitGoogleLogging("MyGlog");

    //设置log打印文件位置
    google::SetLogDestination(google::GLOG_INFO, "./myInfo");

    //设置log只打印在当前终端下
    FLAGS_logtostderr = 1;

    //打印
    LOG(WARNING) << "TEST";

    //使用完之后记得关闭，防止内存泄漏
    google::ShutdownGoogleLogging();
}