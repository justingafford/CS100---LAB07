#ifndef DOUBLEOP_H
#define SCIOP_H
#include "base_factory.hpp"
#include "op.hpp"
#include <sstream>


class SciOp : public Op
{
    protected:
        double num;
    public:
        SciOp() { num = 0; };
        SciOp(double n) { num = n; };
        double evaluate() {};
        string stringify() {
            ostringstream obj;
            obj << std::scientific;
            obj << num;
            string i = obj.str();
            return to_string(i);
        };      
};

#endif
