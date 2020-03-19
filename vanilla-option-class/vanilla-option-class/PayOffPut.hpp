//
//  PayOffPut.hpp
//  payoff-class
//

#ifndef PayOffPut_hpp
#define PayOffPut_hpp

#include <stdio.h>
#include "PayOff.hpp"

class PayOffPut: public PayOff{
public:
    PayOffPut(double Strike);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut();
    virtual PayOff* clone() const;
    
private:
    double Strike;
};

#endif
