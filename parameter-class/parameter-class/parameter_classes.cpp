//
//  parameter_classes.cpp
//  parameter-class
//

#include "parameter_classes.hpp"

// ParameterBridge
ParameterBridge::ParameterBridge(const Parameter& innerParameter){
    this->ParameterPtr = innerParameter.clone();
}

ParameterBridge::ParameterBridge(const ParameterBridge& original){
    this->ParameterPtr = original.ParameterPtr->clone();
}

ParameterBridge& ParameterBridge::operator=(const ParameterBridge& original){
    if(this != &original){
        delete this->ParameterPtr;
        this->ParameterPtr = original.ParameterPtr->clone();
    }
    
    return *this;
}

ParameterBridge::~ParameterBridge(){
    delete this->ParameterPtr;
}

Parameter* ParameterBridge::GetParameterPtr() const{
    return this->ParameterPtr;
}


// ParameterConstant
ParameterConstant::ParameterConstant(double constant){
    this->Constant = constant;
    this->ConstantSquare = constant * constant;
}

Parameter* ParameterConstant::clone() const{
    return new ParameterConstant(*this);
}

double ParameterConstant::Integral(double time1, double time2) const{
    return (time2 - time1)*this->Constant;
}

double ParameterConstant::IntegralSquare(double time1, double time2) const{
    return (time2 - time1)*this->ConstantSquare;
}



