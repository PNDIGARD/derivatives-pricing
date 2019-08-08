# Derivatives pricing
In this project, I implement in C++ various models that compute derivatives prices. I apply what I've learned in Mark Joshi's C++ Design patterns and derivatives pricing (Second Edition).  
The idea is not to attempt to cover all sorts of financial models but instead examine a few in depth with the objective at all times of using them to illustrate certain Obect-Oriented ideas.

I start with a simple Monte Carlo model that prices European calls, then I implement more complex models using classes.

### A simple Monte Carlo model
The code is available in the folder "simple-monte-carlo-pricer".
I start with the well known Black-Scholes result which states that the price of a European call option equals the expectancy of its compounded pay-off, and apply the basic Monte Carlo method to compute this expectancy.

The result is a program that asks the user to give the varibles defining the call (strike, spot, volatility, risk-free rate...) and return the call's price.

### A pay-off class
In progress
