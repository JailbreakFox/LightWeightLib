//
// Created by xuyanghe on 2020-11-18.
//
#include <unitTest.h>

int Foo(int a,int b)
{
   if(0 == a||0 == b)
   throw "don't do that";
   int c = a%b;
   if (0 == c)
  {
     return b;
  }
  return Foo(b,c);
}

/*!
 * \brief test 启动10次，检测控制中心能否保持单例+控制中心能否正常退出
 */
TEST_F(UnitTest, test)
{
    EXPECT_EQ(2,Foo(4,10));
    EXPECT_EQ(6,Foo(30,18));
}
