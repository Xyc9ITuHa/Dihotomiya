//
// Created by хус on 23.04.2025.
//

#ifndef DIHOTOMIYA_H
#define DIHOTOMIYA_H
#include <functional>


class Dyhotomiya { // private:
    double a; // left endpoint
    double b; // right endpoint
    double eps; // tolerance
    public:
    Dyhotomiya();
    ~Dyhotomiya(); // destructor
    //Setters
    void setVolumes(double a, double b);
    void setTolerance(double eps);
    //Getters
    double getLeftEndpoint() const; //a
    double getRightEndpoint() const; //b
    double getTolerance() const; //eps

    double solve (std::function<double(double)> func) ;
    bool check (std::function<double(double)> func) ;
};


#endif //DIHOTOMIYA_H
