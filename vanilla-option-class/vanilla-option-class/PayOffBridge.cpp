//
//  PayOffBridge.cpp
//  vanilla-option-class
//

#include "PayOffBridge.hpp"

PayOffBridge::PayOffBridge(const PayOffBridge& original){
    this->ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff){
    this->ThePayOffPtr = innerPayOff.clone();
}

PayOffBridge::~PayOffBridge(){
    delete this->ThePayOffPtr;
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original){
    if(this != &original){
        delete this->ThePayOffPtr;
        this->ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    
    return *this;
}

PayOff* PayOffBridge::GetThePayOffPtr() const{
    return this->ThePayOffPtr;
}
