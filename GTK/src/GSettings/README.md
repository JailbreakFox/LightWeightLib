# GSettings
https://wikidev.uniontech.com/index.php?title=GSettings_简介
gio 提供了 GKeyFile 结构来处理 keyfile 文件，在这里只介绍使用 dconf 作为 backend 的使用方法。

# 环境配置
要在C++程序中使用GSettings，需要 #include <gio/gio.h>，该头文件在cmake添加了gtk工具以后即可使用

# 配置文件
GSettings的配置文件是 xml 格式的
文件需以 .gschema.xml 结尾，文件名通常与 id 相同，本例中可以即使用com.deepin.test.gschema.xml
配置文件安装在 /usr/share/glib-2.0/schemas/ 目录下
手动添加进去的文件需要执行 sudo glib-compile-schemas /usr/share/glib-2.0/schemas/ 让其生效

# 运行步骤
```sh
cmake ..
make
# 将com.deepin.test.gschema.xml安装到/usr/share/glib-2.0/schemas/下
sudo make install

# 使GSettings的配置文件生效
sudo glib-compile-schemas /usr/share/glib-2.0/schemas/
```
