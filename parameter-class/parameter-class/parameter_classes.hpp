//
//  parameter_classes.hpp
//  parameter-class
//


#ifndef parameter_classes_hpp
#define parameter_classes_hpp

#include <stdio.h>

class Parameter{
public:
    Parameter(){}
    virtual Parameter* clone() const =0;
    virtual double Integral(double time1, double time2) const =0;
    virtual double IntegralSquare(double time1, double time2) const =0;
    virtual ~Parameter(){}
    
private:
};


class ParameterBridge{
public:
    ParameterBridge(const Parameter& innerParameter);
    ParameterBridge(const ParameterBridge& original);
    ParameterBridge& operator=(const ParameterBridge& original);
    ~ParameterBridge();
    Parameter* GetParameterPtr() const;
    
private:
    Parameter* ParameterPtr;
};


class ParameterConstant : public Parameter{
public:
    ParameterConstant(double constant);
    virtual Parameter* clone() const;
    virtual double Integral(double time1, double time2) const;
    virtual double IntegralSquare(double time1, double time2) const;
    
private:
    double Constant;
    double ConstantSquare;
};

#endif
