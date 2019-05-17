fndef_SCIRAND_H
#define SCIRAND_H

#include "base_factory.hpp"
#include <sstream>


class SciRand : public Rand
{
    Rand* createRand()
    {
        ostringstream obj;
        obj << std::scientific;
        double value = rand()%100;
        obj << value;
        string i = obj.str();
        SciRand* temp = new SciRand(i);
        return temp ;
    }

}

#endif

