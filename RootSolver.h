#include <string>

#include "Function.h"

#ifndef RootSolver_H
#define RootSolver_H

class RootSolver {
private:
    std::string expression_string;
    Function foo;
public:
    RootSolver();
    void setString(std::string expression_string);
    double bissectionMethod(double start, double end, double thr, int maxIttr);
    double falsePositionMethod(double start, double end, double thrInterval, double thrFunction, int maxIttr);
    double fixedPointMethod(double x0, double thrInterval, double thrFunction, int maxIttr);
    double newtonMethod(double x0, double thrInterval, double thrFunction, int maxIttr);
    double secantMethod(double x0, double x1, double thrInterval, double thrFunction, int maxIttr);
};

#endif