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
#include "Op.hpp"
#include "Rand.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"
#include "gtest/gtest.h"

TEST(OpTests, DoubleTest)  {
    BaseFactory* factory = new DoubleFactory;
    Op* doub = factory->createOp(420.6969696969);
    ASSERT_EQ(doub->stringify(),"420.696970");
}

TEST(OpTests, SciTest)  {
    BaseFactory* factory = new SciFactory;
    Op* sci = factory->createOp(420.6969696969);
    ASSERT_EQ(sci->stringify(),"4.206970e+02");
}

TEST(OpTests, PrecisionTest)  {
    BaseFactory* factory = new PrecisionFactory;
    Op* precis = factory->createOp(420.6969696969);
    ASSERT_EQ(precis->stringify(),"420.696969697");
}
//create randmock for testing, because we cannot know what numbers are, because they are random.
class RandMock: public Rand {
    public:
        RandMock() {};

        virtual double evaluate() { return 314.159265359; }
        virtual string stringify() { return "314.159265359"; }
};

TEST(RandTests, DoubleTest)  {
    BaseFactory* factory = new DoubleFactory;
    Rand* randDouble = factory->createRand();
    ASSERT_EQ(randDouble->stringify(),"314.159265");
}

TEST(RandTests, SciTest)  {
    BaseFactory* factory = new SciFactory;
    Rand* randSci = factory->createRand();
    ASSERT_EQ(randSci->stringify(),"3.14159e+02");
}

TEST(RandTests, PrecisionTest)  {
    BaseFactory* factory = new PrecisionFactory;
    Rand* randPrecision = factory->createRand();
    ASSERT_EQ(randPrecision->stringify(),"314.159265359");
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
