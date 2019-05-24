#include "base.hpp"
#include "base_factory.hpp"
#include "scifactory.hpp"
#include "doublefactory.hpp"
#include "precisionfactory.hpp"
#include "scirand.hpp"
#include "precisionrand.hpp"
#include "doublerand.hpp"
#include "sciop.hpp"
#include "precisionop.hpp"
#include "doubleop.hpp"
#include "Op.cpp"
#include "Rand.cpp"
#include "Mult.cpp"
#include "Div.cpp"
#include "Add.cpp"
#include "Sub.cpp"
#include "Pow.cpp"
#include "gtest/gtest.h"

TEST(IndvClassTest, OpTest)  {

Op* op1 = new Op(5.0); 
Op* op2 = new Op(2.0); 

EXPECT_EQ(op1 -> evaluate(), 5.0);
EXPECT_EQ(op2 ->stringify(), "2.000000");
}
TEST(IndvClassTest, AddTest)  {
Op* op1 = new Op(5.0); 
Op* op2 = new Op(2.0); 

Add* add1 = new Add(op1, op2);
EXPECT_EQ(add1->evaluate(), 7);
EXPECT_EQ(add1->stringify(), "5.000000+2.000000");
}

TEST(IndvClassTest, SubTest)  {
Op* op1 = new Op(5.0); 
Op* op2 = new Op(2.0); 

Sub* sub1 = new Sub(op1 , op2);
EXPECT_EQ(sub1->evaluate(), 3);
EXPECT_EQ(sub1->stringify(), "5.000000-2.000000");
}

TEST(IndvClassTest, MultTest)  {
Op* op1 = new Op(5.0); 
Op* op2 = new Op(2.0); 

Mult* mult1 = new Mult(op1 , op2);
EXPECT_EQ(mult1  ->evaluate(),  10);
EXPECT_EQ(mult1  ->stringify(), "5.000000*2.000000");
}

TEST(IndvClassTest, DivTest)  {
Op* op1 = new Op(5.0); 
Op* op2 = new Op(2.0); 

Div* div1 = new Div(op1  , op2);
EXPECT_EQ(div1  ->evaluate(),  2.5);
EXPECT_EQ(div1  ->stringify(), "5.000000/2.000000");
}

TEST(IndvClassTest, PowTest)  {
Op* op1 = new Op(5.0); 
Op* op2 = new Op(2.0); 

Pow* pow1 = new Pow(op1, op2);
EXPECT_EQ(pow1  ->evaluate(),  25);
EXPECT_EQ(pow1  ->stringify(), "5.000000**2.000000");
}

TEST(ArithTest, OpNumber)  {

Op* op1 = new Op(5.0); 
Op* op2 = new Op(7.0); 
Op* op3 = new Op(2.0); 

EXPECT_EQ(op1 -> evaluate(), 5.0);
EXPECT_EQ(op1 ->stringify(), "5.000000");

Add* add1 = new Add(op1, op2);
EXPECT_EQ(add1->evaluate(), 12);
EXPECT_EQ(add1->stringify(), "5.000000+7.000000");

Sub* sub1 = new Sub(add1 , op2);
EXPECT_EQ(sub1->evaluate(), 5);
EXPECT_EQ(sub1->stringify(), "12.000000-7.000000");

Mult* mult1 = new Mult(sub1 , op3);
EXPECT_EQ(mult1  ->evaluate(),  10);
EXPECT_EQ(mult1  ->stringify(), "5.000000*2.000000");

Div* div1 = new Div(mult1  , op3);
EXPECT_EQ(div1  ->evaluate(),  5);
EXPECT_EQ(div1  ->stringify(), "10.000000/2.000000");

Pow* pow1 = new Pow(div1, op3);
EXPECT_EQ(pow1  ->evaluate(),  25);
EXPECT_EQ(pow1  ->stringify(), "5.000000**2.000000");
}

class RandMock: public Base {
    public:
        RandMock() { };

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
};


TEST(ArithTest, RandNumber)  {
RandMock* ra1 = new RandMock(); 
RandMock* ra2 = new RandMock(); 
RandMock* ra3 = new RandMock(); 
Op* newop = new Op(2.0);

EXPECT_EQ(ra1->evaluate(), 7.5);
EXPECT_EQ(ra1->stringify(), "7.5");

Add* add1 = new Add(ra1 , ra2 );
EXPECT_EQ(add1 ->evaluate(), 15);
EXPECT_EQ(add1 ->stringify(), "7.500000+7.500000");

Sub* sub1 = new Sub(add1 , ra2 );
EXPECT_EQ(sub1 ->evaluate(), 7.5);
EXPECT_EQ(sub1 ->stringify(), "15.000000-7.500000");

Mult* mult1 = new Mult(sub1 , ra3 );
EXPECT_EQ(mult1 ->evaluate(),  56.25);
EXPECT_EQ(mult1 ->stringify(), "7.500000*7.500000");

Div* div1 = new Div(mult1  , ra3 );
EXPECT_EQ(div1 ->evaluate(), 7.5);
EXPECT_EQ(div1 ->stringify(), "56.250000/7.500000");

Pow* pow1 = new Pow(div1, newop );
EXPECT_EQ(pow1 -> evaluate(), 56.250000);
EXPECT_EQ(pow1  -> stringify(), "7.500000**2.000000");
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
