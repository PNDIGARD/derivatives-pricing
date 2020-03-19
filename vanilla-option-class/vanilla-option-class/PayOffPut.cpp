//
//  PayOffPut.cpp
//  payoff-class
//

#include "PayOffPut.hpp"
#include <algorithm>

PayOffPut::PayOffPut(double Strike){
    this->Strike = Strike;
}

double PayOffPut::operator()(double Spot) const{
    return std::max(this->Strike - Spot, 0.0);
}

PayOffPut::~PayOffPut(){}

PayOff* PayOffPut::clone() const{
    return new PayOffPut(*this);
}
