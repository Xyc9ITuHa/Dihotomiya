//
// Created by хус on 23.04.2025.
//

#include "Newthon.h"


Newton::Newton() {
    initGuess = 1.0;     // Default initial guess
    eps = 0.0001;  // Default tolerance
    h = 0.00001;    // Default step for numerical differentiation
    maxIter = 100; // Default maximum iterations
}

Newton::~Newton() {
    // Destructor implementation
}

void Newton::setInitialGuess(double initGuessValue) {
    this->initGuess = initGuessValue;
}

void Newton::setTolerance(double epsValue) {
    this->eps = epsValue;
}

void Newton::setDifferentiationStep(double hValue) {
    this->h = hValue;
}

void Newton::setMaxIterations(int maxIterValue) {
    this->maxIter = maxIterValue;
}

double Newton::derivative(std::function<double(double)> func, double x) {
    // Numerical differentiation using finite difference
    return (func(x + h) - func(x)) / h;
}

double Newton::solve(std::function<double(double)> func) {
    double x = initGuess;
    double x_next;

    for (int i = 0; i < maxIter; i++) {
        double fucntionValue = func(x);
        double derFuncValue = derivative(func, x);

        // Check for division by zero
        if (std::abs(derFuncValue) < eps) {
            std::cout << "Derivative is too close to zero. Method may not converge." << std::endl;
            return x;
        }

        // Newton's formula
        x_next = x - fucntionValue / derFuncValue;
        //              f(x(n))
        // x(n+1) = x - --------
        //              f'(x(n))'

        // Check convergence
        if (std::abs(x_next - x) < eps) {
            return x_next;
        }

        x = x_next;
    } // I hate math

    std::cout << "Maximum iterations reached. The method may not have converged." << std::endl;
    return x;
}