#ifndef DOUBLEFACTORY_H
#define DOUBLEFACTORY_H
#include "basefactory.hpp"
#include "doubleop.hpp"
#include "doublerand.hpp"
class DoubleFactory : public BaseFactory
{
 public:
     DoubleFactory(){};
     Op* createOp(double value){
         DoubleOp* temp = new DoubleOp* (value); 
         return temp;
     };
     Rand* createRand(){return new DoubleRand()};

}

