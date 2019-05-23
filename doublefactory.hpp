#ifndef DOUBLEFACTORY_H
#define DOUBLEFACTORY_H

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

