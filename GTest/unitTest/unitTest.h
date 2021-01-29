//
// Created by xuyanghe on 2020-11-18.
//
#ifndef UNITTEST_H
#define UNITTEST_H
#include <gtest/gtest.h>

class UnitTest : public ::testing::Test
{
public:
    UnitTest() {}
    virtual ~UnitTest() {}

    virtual void SetUp() {}

    virtual void TearDown() {}
};

#endif // UNITTEST_H
