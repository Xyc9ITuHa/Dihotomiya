//
// Created by хус on 23.04.2025.
//

#include "Dihotomiya.h"

// Dihotomiya.cpp
#include "Dihotomiya.h"
#include <iostream>
#include <cmath>

Dihotomiya::Dihotomiya() {
    a = 0.0;
    b = 1.0;
    eps = 0.0001;
}

Dihotomiya::~Dihotomiya() {
    // Destructor implementation
}

void Dihotomiya::setVolumes(double a_val, double b_val) {
    this->a = a_val;
    this->b = b_val;
}

void Dihotomiya::setTolerance(double eps_val) {
    this->eps = eps_val;
}

double Dihotomiya::getLeftEndpoint() const {
    return a;
}

double Dihotomiya::getRightEndpoint() const {
    return b;
}

double Dihotomiya::getTolerance() const {
    return eps;
}

bool Dihotomiya::check() {
    // Check if the function changes sign in the interval [a, b]
    return a * b < 0;
}

double Dihotomiya::solve() {
    double left = a;
    double right = b;

    // Check if there's a solution in the interval
    if (!check()) {
        std::cout << "No solution in the given interval!" << std::endl;
        return (left + right) / 2; // Return midpoint as default
    }

    double c;

    // Bisection algorithm
    while ((right - left) > eps) {
        c = (left + right) / 2;

        if (left * c < 0) {
            // Solution is in the left half
            right = c;
        } else {
            // Solution is in the right half
            left = c;
        }
    }

    // Return the midpoint of the final interval
    return (left + right) / 2;
}