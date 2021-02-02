#include "mysql.h"

#include<iostream>

int main() {
    MYSQL *connection;
    int res;
    connection = mysql_init(nullptr); // 初始化数据库连接变量
    //"root":数据库管理员 "":root密码 "test":数据库的名字
    if(mysql_real_connect(m_connection, "localhost", "root", "123456", "test", 0, nullptr, CLIENT_FOUND_ROWS)) {
        qInfo() << "connect success!\n";
        res = mysql_query(m_connection, "insert into test values('user','123456')");
        qInfo() << (res ? "error\n" : "OK\n");
        mysql_close(m_connection);
    } else {
        std::cout << "connect fail!" << std::endl;
    }
}
