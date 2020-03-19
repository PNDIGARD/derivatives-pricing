//
//  main.cpp
//  vanilla-option-class
//

#include <iostream>
#include "VanillaOption.hpp"
#include "PayOffCall.hpp"
#include "PayOffPut.hpp"
#include "MonteCarloPricer.hpp"
using namespace std;

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    int NumberOfPaths;
    
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nStrike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    
    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);
    double result = simpleMonteCarloPricer(theOption,
                                           Spot,
                                           Vol,
                                           r,
                                           NumberOfPaths);
    cout <<"\nthe call price is " << result << "\n";
    
    PayOffPut otherPayOff(Strike);
    VanillaOption otherOption(otherPayOff, Expiry);
    theOption = otherOption;
    result = simpleMonteCarloPricer(theOption,
                                    Spot,
                                    Vol,
                                    r,
                                    NumberOfPaths);
    cout <<"\nthe put price is " << result << "\n";
    
    double tmp;
    cin >> tmp;
    
    return 0;
}
