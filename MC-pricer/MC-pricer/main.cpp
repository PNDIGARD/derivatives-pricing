//
//  main.cpp
//  MC-pricer
//


#include <iostream>
#include "MonteCarloPricer.hpp"
using namespace std;

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    int NumberOfPaths;

    // asking the user for paramters defining the call
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

    // giving the user the price of such call
    double price = simpleMonteCarloPricer(Expiry,
                                          Strike,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);
    cout<<"The price of this European call is "<<price<<"\n";

    // give time to the user to read the price
    double tmp;
    cout<<"\n'q' to quit\n";
    cin>>tmp;
    return 0;
}
