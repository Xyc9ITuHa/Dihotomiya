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

//so basically we pass a function that is double and returns double
bool Dihotomiya::check(std::function<double(double)> func) {
    // Check if the function changes sign in the interval [a, b]
    return func(a) * func(b) < 0;
}

//and then we do all this stuff I'm tired of coding
double Dihotomiya::solve(std::function<double(double)> func) {
    double left = a;
    double right = b;

    // Check if there's a solution in the interval
    if (!check(func)) {
        std::cout << "No solution in the given interval!" << std::endl;
        return (left + right) / 2; // Return midpoint as default
    }

    double middle;

    // Bisection algorithm
    while ((right - left) > eps) {
        middle = (left + right) / 2;

        // mid func check :P
        if (func(left) * func(middle) < 0) {
            // Solution is in the left half
            right = middle;
        } else {
            // Solution is in the right half
            left = middle;
        }
    }

    // Return the midpoint of the final interval
    return (left + right) / 2;
}

/*
Have you ever died in a nightmare?
Woke up surprised you hadn't earned your fate?
Have you ever felt like Atlas, threw your back out on the axis
And collapsed and threw the planet away?
Everyone's just blood in an ice tray
A vampire picking flowers out in the sun
Run your diagnostic tests, it's posited nobody dies agnostic
But we still dial 9-1-1
And now we're singing
Ooh, could you take a look at me? (It's the norm for animals, it's the norm for chemicals)
Am I bad, am I bad, am I bad, am I really that bad? (It's the norm for particles, eye for eye for tooth)
And now we're singing, ooh (it's the norm for chemicals)
Whatever you think of me (it's the norm for particles)
If you were in my shoes (yes, it's only natural)
You'd walk the same damn miles I do
We're only tuning to the tone of the bell curve now
Ask not for whom it tolls
But with my head up in the clouds I can see so much ground
And from up here, you look like ants in a row
It doesn't take a killer to murder
It only takes a reason to kill
We've all got evidence of innocence, it's "everything's coincidence"
The difference twixt fate and free will is whether you're singing
Ooh, could you take a look at me? (It's the norm for animals, it's the norm for chemicals)
Am I bad, am I bad, am I bad, am I really that bad? (It's the norm for particles, I for I for tooth)
And now we're singing, ooh (it's the norm for chemicals)
Whatever you think of me (it's the norm for particles)
If you were in my shoes (yes, it's only natural!)
You'd walk the same damn miles I do
Oh, oh, right!
So if you wash your hands of where you've been until you flood the second floor
Neatly fold your skeletons, but still can't shut the closet door
The only ones in need of love are those who don't receive enough
So evil ones should get a little more
You, could you take a look at me? (You could break an angel's fall and ignore the Devil's call)
Am I bad, am I bad, am I bad, am I really that bad? (Still forsaken shoulders fall silent now)
And now we're singing, ooh (it's no more than cultural)
Whatever you think of me (you and me inseparable)
If the shoe fits, would you walk that mile? (It's a small hell, after all)
You could put it on the other foot, it's the same size
You, could you take a look at me? (Man no more than animal is made of moral chemicals)
Am I bad, am I bad, am I bad, am I really that bad? (Any form mechanical, thank you, God)
We're singing, ooh (from the hordes of cannibals)
Whatever you think of me (to psych wards of hospitals)
If you were in my shoes (it's a small world, after all)
You'd see I wear the same size as you
Oh, oh, right!
 */