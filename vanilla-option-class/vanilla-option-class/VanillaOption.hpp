//
//  VanillaOption.hpp
//  vanilla-option-class
//

#ifndef VanillaOption_hpp
#define VanillaOption_hpp

#include <stdio.h>
#include "PayOffBridge.hpp"

class VanillaOption{
public:
    VanillaOption(const PayOffBridge& ThePayOff, double Expiry);
    double OptionPayOff(double Spot) const;
    double GetExpiry() const;
    
private:
    double Expiry;
    PayOffBridge ThePayOff;
};

#endif 
