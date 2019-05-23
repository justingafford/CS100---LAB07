#ifndef DOUBLERAND_H
#define DOUBLERAND_H
#include "base_factory.hpp"
#include "Rand.hpp"
#include <sstream>


class DoubleRand : public Rand
{
    protected:
        double num;
    public:
        DoubleRand() { num = rand % 100; };
        double evaluate() {};
        string stringify() {
            ostringstream obj;
            obj << std::scientific;
            obj << num;
            string i = obj.str();
            return i;
        };      
};

#endif
