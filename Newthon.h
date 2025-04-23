//
// Created by хус on 23.04.2025.
//

#ifndef NEWTHON_H
#define NEWTHON_H

#include <functional>
#include <iostream>
#include <cmath>
class Newton {
    double initGuess;      // Initial guess gotta figure out how to do that
    double eps;     // Tolerance
    double h;       // Step for numerical differentiation  THAT ALL MEANS I CANT UNDERSTAND
    int maxIter;    // Maximum number of iterations

public:
    Newton();
    ~Newton();

    // Setters
    void setInitialGuess(double x0);
    void setTolerance(double eps);
    void setDifferentiationStep(double h);
    void setMaxIterations(int maxIter);
    // Solving method
    double solve(std::function<double(double)> func);
    // Numerical differentiation
    double derivative(std::function<double(double)> func, double x);
};

#endif //NEWTHON_H