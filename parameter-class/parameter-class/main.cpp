//
//  main.cpp
//  parameter-class
//


#include <iostream>
#include "MonteCarloPricer.hpp"
#include "parameter_classes.hpp"
using namespace std;

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    int NumberOfPaths;

    cout<<"\nEnter expiry\n";
    cin>>Expiry;
    cout<<"\nEnter strike\n";
    cin>>Strike;
    cout<<"\nEnter Spot\n";
    cin>>Spot;
    cout<<"\nEnter volatility\n";
    cin>>Vol;
    cout<<"\nEnter risk-free rate\n";
    cin>>r;
    cout<<"\nEnter number of paths\n";
    cin>>NumberOfPaths;
    
    ParameterConstant VolObject(Vol);
    ParameterConstant rObject(r);
    //ParameterBridge vv(VolObject);
    //ParameterBridge rr(rObject);

    double price = simpleMonteCarloPricer_Call(Expiry,
                                               Strike,
                                               Spot,
                                               VolObject,
                                               rObject,
                                               NumberOfPaths);
    
    cout<<"The price of this European call is "<<price<<"\n";

    double tmp;
    cout<<"\n'q' to quit\n";
    cin>>tmp;
    
    return 0;
}
