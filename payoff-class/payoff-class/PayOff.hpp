//
//  PayOff.hpp
//  payoff-class
//


#ifndef PayOff_hpp
#define PayOff_hpp

#include <stdio.h>

class PayOff {
public:
    enum OptionType {call, put};
    PayOff(double Strike, OptionType TheOptionsType);
    double operator()(double Spot) const;
private:
    double Strike;
    OptionType TheOptionsType;
};

#endif
