//
// Created by PC on 23.09.2021.
//
#include "gtest/gtest.h"
#include "../Vector.h"
using namespace Prog3;
TEST(constructor, defaultConstructor)
{
    Vector a1;
    ASSERT_EQ(0, a1.getCurSize());
}
TEST(constructor, initConstructors)
{
    double numbers[10] = {0};
    Vector a(4);
    ASSERT_EQ(1, a.getCurSize());
    ASSERT_EQ(4, a.getNum(0));
    Vector b(10, numbers);
    ASSERT_EQ(10, b.getCurSize());
    ASSERT_EQ(0, b.getNum(9));

}

TEST(methods, add_sub)
{
    double numbers[10] = {1};
    Vector a(4);
    Vector b(10, numbers);
    Vector *c = a.addition(b);
    ASSERT_EQ(5, (b.addition(a))->getNum(0));
    ASSERT_EQ(-3, (b.subtraction(a))->getNum(0));
}
TEST(methods, scalar)
{
    double numbers[10] = {1};
    Vector a(4);
    Vector b(10, numbers);
    ASSERT_EQ(4, b.scalarProduct(a));
}
TEST(methods, normOfVector)
{
    double numbers[10] = {-100};
    Vector b(10, numbers);
    ASSERT_EQ(100, b.normOfVector());
}

TEST(methods, addElement)
{
    double numbers[10] = {-100};
    Vector b(10, numbers);
    Vector a(4);
    a.addElement(3);
    ASSERT_EQ(3, a.getNum(1));
}
TEST(methods, norma)
{
    double numbers[10] = {-100};
    Vector b(10, numbers);
    ASSERT_EQ(100, b.normOfVector());
}