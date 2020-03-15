//
//  main.cpp
//  payoff-class
//


#include "MonteCarloPricer.hpp"
#include "PayOff.hpp"
#include <iostream>
using namespace std;

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    int NumberOfPaths;

    // asking the user for paramters defining the vanilla option
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

    // giving the user the price of such call and put
    PayOff callPayOff = PayOff(Strike, PayOff::call);
    PayOff putPayOff = PayOff(Strike, PayOff::put);
    
    double callPrice = simpleMonteCarloPricer(callPayOff,
                                              Expiry,
                                              Spot,
                                              Vol,
                                              r,
                                              NumberOfPaths);
    double putPrice = simpleMonteCarloPricer(putPayOff,
                                             Expiry,
                                             Spot,
                                             Vol,
                                             r,
                                             NumberOfPaths);
    
    cout<<"The prices are:\n"<<"Call: "<<callPrice<<endl<<"Put :"<<putPrice<<endl;

    // give time to the user to read the price
    double tmp;
    cout<<"\n'q' to quit\n";
    cin>>tmp;
    return 0;
}
