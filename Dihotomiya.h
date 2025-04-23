//
// Created by хус on 23.04.2025.
//

#ifndef DIHOTOMIYA_H
#define DIHOTOMIYA_H



class Dihotomiya {
    double a;
    double b;
    double eps;
    public:
    Dihotomiya();
    ~Dihotomiya();
    void setVolumes(double a, double b);
    void setTolerance(double eps);
};


#endif //DIHOTOMIYA_H
