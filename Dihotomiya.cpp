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

bool Dihotomiya::check(std::function<double(double)> func) {

}

double Dihotomiya::solve(std::function<double(double)> func) {

}