//
//  PayOffBridge.hpp
//  vanilla-option-class
//


#ifndef PayOffBridge_hpp
#define PayOffBridge_hpp

#include <stdio.h>
#include "PayOff.hpp"

class PayOffBridge
{
public:
    PayOffBridge(const PayOff& innerPayOff);
    
    PayOffBridge(const PayOffBridge& original);
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
    
    PayOff* GetThePayOffPtr() const;
    
private:
    PayOff* ThePayOffPtr;
};

#endif
