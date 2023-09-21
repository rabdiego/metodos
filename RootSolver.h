#include <string>

#include "Function.h"

#ifndef RootSolver_H
#define RootSolver_H

class RootSolver {
private:
    std::string expression_string;
public:
    void setString(std::string expression_string);
    double bissectionMethod(double start, double end, double thr, int maxIttr);
    double falsePositionMethod(double start, double end, double thrInterval, double thrFunction, int maxIttr);
};

#endif