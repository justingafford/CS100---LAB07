#ifndef SCIFACTORY_H
#define SCIFACTORY_H

class SciFactory : public BaseFactory
{
 public:
     SciFactory(){};
     SciOp* createOp(double value){SciOp* temp = new SciOp* value; return temp;};
     SciRand* createRand(){return new SciRand()};

}
