#!/bin/sh

# 参考网址：https://github.com/carloscn/blog/issues/43
# 可执行程序名
appname=$1
# 目标文件夹
dst=./$2
# 利用 ldd 提取依赖库的具体路径
liblist=$(ldd $appname | awk '{ if (match($3,"/")){ printf("%s "), $3 } }')
# 目标文件夹的检测
if [ ! -d $dst ];then
                mkdir $dst
fi
# 拷贝库文件和可执行程序到目标文件夹
cp $liblist $dst
cp $appname $dst


# dpkg -b package NetAssistant-v1.1.deb