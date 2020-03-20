//
//  MonteCarloPricer.cpp
//  MC-pricer
//


#include "MonteCarloPricer.hpp"
#include <random>

double simpleMonteCarloPricer_Call(double Expiry,
                                   double Strike,
                                   double Spot,
                                   const ParameterBridge &Vol,
                                   const ParameterBridge &r,
                                   int NumberOfPaths){
    std::mt19937 mt_rand(42);
    std::normal_distribution<double> gaussian(0.0, 1.0);
    double variance = Vol.GetParameterPtr()->IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double drift = r.GetParameterPtr()->Integral(0, Expiry);
    double S = Spot * exp(drift - 0.5*variance);
    double runningSum = 0;
    
    for(int i = 0; i < NumberOfPaths; i++){
        double thisS = S * exp(rootVariance*gaussian(mt_rand));
        double thisPayOff = thisS - Strike > 0 ? thisS - Strike : 0;
        runningSum += thisPayOff;
    }
    
    return exp(-drift*Expiry) * (runningSum / NumberOfPaths);
}
