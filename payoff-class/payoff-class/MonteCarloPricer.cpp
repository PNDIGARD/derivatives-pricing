//
//  MonteCarloPricer.cpp
//  payoff-class
//

#include "MonteCarloPricer.hpp"
#include <random>

double simpleMonteCarloPricer(const PayOff& thePayOff,
                              double Expiry,
                              double Spot,
                              double Vol,
                              double r,
                              int NumberOfPaths){
    std::mt19937 mt_rand(42);
    std::normal_distribution<double> gaussian(0.0, 1.0);
    double S = Spot * exp((r - Vol*Vol)*Expiry);
    double runningSum = 0;
    
    for(int i = 0; i < NumberOfPaths; i++){
        double thisS = S * exp(Vol*sqrt(Expiry)*gaussian(mt_rand));
        double thisPayOff = thePayOff(thisS);
        runningSum += thisPayOff;
    }
    
    return exp(-r*Expiry) * (runningSum / NumberOfPaths);
}
