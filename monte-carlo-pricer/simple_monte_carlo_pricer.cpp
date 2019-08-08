// imports
#include <random>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// functions declaration
double simpleMonteCarloPricer(double Expiry,
                              double Strike,
                              double Spot,
                              double Vol,
                              double r,
                              unsigned long NumberOfPaths);

// main function, it asks the user paramters defining the call and return the
// price of the call
int main()
{
  double Expiry;
  double Strike;
  double Spot;
  double Vol;
  double r;
  unsigned long NumberOfPaths;

  // ask the user for paramters defining the call
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

  // give the user the price of such call
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
}

// functions definition
double simpleMonteCarloPricer(double Expiry,
                              double Strike,
                              double Spot,
                              double Vol,
                              double r,
                              unsigned long NumberOfPaths)
{
  // compute everything we can before loop
  double variance = Vol * Vol * Expiry;
  double rootVariance = sqrt(variance);
  double itoCorrection = -0.5 * variance;
  double movedSpot = Spot * exp(r * Expiry + itoCorrection);

  // instanciate variables updated during the loop
  double thisSpot;
  double runningSum;

  // random gaussion generator
  random_device rd;
  mt19937 generator(rd());
  normal_distribution<float> d(0,1);

  // Monte Carlo simulation
  for(int i = 0; i < NumberOfPaths; i++){
    double x = d(generator);
    thisSpot = movedSpot * exp(rootVariance * x);
    double payoff = thisSpot - Strike;
    if(payoff < 0){
      payoff = 0;
    }
    runningSum += payoff;
  }

  double mean = runningSum / NumberOfPaths;
  double meanCompounded = exp(-r * Expiry) * mean;

  return meanCompounded;
}
