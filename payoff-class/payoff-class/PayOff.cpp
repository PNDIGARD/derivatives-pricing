//
//  PayOff.cpp
//  payoff-class
//


#include "PayOff.hpp"
#include <algorithm>

PayOff::PayOff(double Strike, OptionType TheOptionsType){
    this->Strike = Strike;
    this->TheOptionsType = TheOptionsType;
}

double PayOff::operator()(double Spot) const{
    switch (this->TheOptionsType) {
        case call:
            return std::max(Spot - this->Strike, 0.0);
            break;
            
        case put:
            return std::max(this->Strike - Spot, 0.0);
        break;
            
        default:
            throw("Unknown option type found.");
            break;
    }
}
