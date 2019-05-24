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
    Op* doub = factory->createOp(420.696969696);
    ASSERT_EQ(doub->stringify(),"420.696970");
}

TEST(OpTests, SciTest)  {
    BaseFactory* factory = new SciFactory;
    Op* sci = factory->createOp(420.696969696);
    ASSERT_EQ(sci->stringify(),"4.2696970e+02");
}

TEST(OpTests, PrecisionTest)  {
    BaseFactory* factory = new PrecisionFactory;
    Op* precis = factory->createOp(420.696969696);
    ASSERT_EQ(precis->stringify(),"420.69696969");
}

TEST(RandTests, DoubleTest)  {

}

TEST(RandTests, SciTest)  {

}

TEST(RandTests, PrecisionTest)  {

}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
