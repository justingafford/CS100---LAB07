#ifndef PRECISIONOP_H
#define PRECISIONOP_H
#include "base_factory.hpp"
#include "Op.hpp"
#include <sstream>


class PrecisionOp : public Op
{
    protected:
        double num;
    public:
        PrecisionOp() { num = 0; };
        PrecisonOp(double n) { num = n; };
        double evaluate() {};
        string stringify() {
            ostringstream obj;
            obj << std::fixed;
            obj << num;
            string i = obj.str();
            return i;
        };      
};

#endif
