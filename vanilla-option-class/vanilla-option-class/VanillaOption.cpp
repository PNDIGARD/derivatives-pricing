//
//  VanillaOption.cpp
//  vanilla-option-class
//

#include "VanillaOption.hpp"

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_)
    : ThePayOff(ThePayOff_), Expiry(Expiry_)
    {}

double VanillaOption::OptionPayOff(double Spot) const{
    return this->ThePayOff.GetThePayOffPtr()->operator()(Spot);
}

double VanillaOption::GetExpiry() const{
    return this->Expiry;
}
