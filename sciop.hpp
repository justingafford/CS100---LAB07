#ifndef_SCIOP_H
#define SCIOP_

#include "base_factory.hpp"
#include <sstream>


class SciOp : public Op
{
    Op* createOp(double value)
    {
        ostringstream obj;
        obj << std::scientific;
        obj << value;
        string i = obj.str();
        SciOp* temp = new SciOp (i);
        return temp ;
    }       

}

#endif
