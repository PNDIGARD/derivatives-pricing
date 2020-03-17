//
//  PayOff.hpp
//  payoff-class
//


#ifndef PayOff_hpp
#define PayOff_hpp

#include <stdio.h>

class PayOff {
public:
    PayOff();
    virtual double operator()(double Spot) const=0;
    virtual ~PayOff();
private:
};

#endif
