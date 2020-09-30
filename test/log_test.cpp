#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char const *argv[])
{
    // 加载配置文件
    el::Configurations conf("E:/WorkSpace/DataStructure/test/log.conf");
    // 配置单一级别的日志
    el::Loggers::reconfigureLogger("default", conf); 
    // 配置所有级别的日志
    el::Loggers::reconfigureAllLoggers(conf);

    LOG(INFO) << "My first into log using default logger";

    return 0;
}
