//
//  main.cpp
//  payoff-class
//


#include "MonteCarloPricer.hpp"
#include "PayOff.hpp"
#include "PayOffCall.hpp"
#include "PayOffPut.hpp"
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
    
    unsigned long optionType;
    cout << "\nenter 0 for call, otherwise put ";
    cin >> optionType;

    // giving the user the price of such call and put
    PayOff* thePayOffPtr;
    
    if(optionType == 0){
        thePayOffPtr = new PayOffCall(Strike);
    }else{
        thePayOffPtr = new PayOffPut(Strike);
    }
    
    double optionPrice = simpleMonteCarloPricer(*thePayOffPtr,
                                              Expiry,
                                              Spot,
                                              Vol,
                                              r,
                                              NumberOfPaths);
    
    cout<<"The price is: "<<optionPrice<<endl;

    // give time to the user to read the price
    double tmp;
    cout<<"\n'q' to quit\n";
    cin>>tmp;
    return 0;
}
