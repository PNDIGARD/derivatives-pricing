//
//  PayOffCall.cpp
//  payoff-class
//

#include "PayOffCall.hpp"
#include <algorithm>

PayOffCall::PayOffCall(double Strike){
    this->Strike = Strike;
}

double PayOffCall::operator()(double Spot) const{
    return std::max(Spot - this->Strike, 0.0);
}

PayOffCall::~PayOffCall(){}
