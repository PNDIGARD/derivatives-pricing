//
//  PayOffCall.hpp
//  payoff-class
//

#ifndef PayOffCall_hpp
#define PayOffCall_hpp

#include <stdio.h>
#include "PayOff.hpp"

class PayOffCall: public PayOff{
public:
    PayOffCall(double Strike);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall();
    
private:
    double Strike;
};

#endif
