# MySQL
Open sql Library

## 安装MySQL
[Linux系统上的安装方法](https://www.jianshu.com/p/276d59cbc529)
*1、官网下载包*
```sh
wget https://dev.mysql.com/get/Downloads/MySQL-5.7/mysql-5.7.24-linux-glibc2.12-x86_64.tar.gz
```

*2、安装到指定文件夹*
```sh
# 解压缩安装包并重命名为 mysql/
mv mysql-5.7.24-linux-glibc2.12-x86_64 /usr/local/mysql

# 创建文件data夹
mkdir /usr/local/mysql/data

# 更改文件夹用户组与权限
chmod -R 755 /usr/local/mysql

# 编译安装并初始化 
./usr/local/mysql/bin/mysqld --initialize --user=mysql --datadir=/usr/local/mysql/data --basedir=/usr/local/mysql

# ！！注意记录日志最末尾位置root@localhost:后的字符串，此字符串为mysql管理员临时登录密码。！！

# 添加软链接(否则终端直接输入mysql无法使用该程序)
ln -s /usr/local/mysql/support-files/mysql.server /etc/init.d/mysql
ln -s /usr/local/mysql/bin/mysql /usr/bin/mysql
service mysql restart

# 登录mysql修改密码
[root@localhost /]#  mysql -u root -p
Enter password:
mysql>set password for root@localhost = password('123456');
```

## 运行项目中的例子
*1、过程化的MySQL C API*
上述两个步骤已经将库文件安装，借助.cmake文件可寻找到对应的库文件，项目文件在MYSQL_C_API下。  
至此已经可以使用"过程化的MySQL C API"

*2、MySQL++ API连接MySQL*

*3、MySQL Connector/C++*
MySQL Connector/C++是MySQL C API的C++封装

## MySQL与C++的使用