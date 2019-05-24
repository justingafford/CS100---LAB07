#ifndef PRECISIONRAND_H
#define PRECISIONRAND_H
#include "base_factory.hpp"
#include "Rand.hpp"
#include <sstream>


class PrecisionRand : public Rand
{
    protected:
        double num;
    public:
        PrecisionRand() { num = rand() % 100; };
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
