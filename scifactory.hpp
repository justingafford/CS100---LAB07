#ifndef SCIFACTORY_H
#define SCIFACTORY_H

class SciFactory : public BaseFactory
{
 public:
     SciFactory(){};
     Op* createOp(double value){
         SciOp* temp = new SciOp* (value); 
         return temp;
     };
     Rand* createRand(){return new SciRand()};

}
