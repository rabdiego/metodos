#include "RootSolver.h"

double absoluteValue(double a) {
    if (a >= 0) {
        return a;
    }
    return -a;
}

void RootSolver::setString(std::string expression_string) {
    this->expression_string = expression_string;
}

double RootSolver::bissectionMethod(double start, double end, double thr, int maxIttr) {
    if (start >= end) {
        throw std::invalid_argument("Beginning of interval is greater than the ending");
    }
    
    Function foo(this->expression_string);

    double functionAtStart = foo.value(start);
    double functionAtEnd = foo.value(end);

    double functionAtPoint;

    if (functionAtStart * functionAtEnd > 0) {
        throw std::invalid_argument("Function does not change its sign between given interval");
    }

    double interval = end - start;
    int ittr = 0;
    double point = (start + end) / 2;

    while (interval > thr && ittr < maxIttr) {
        functionAtPoint = foo.value(point);

        if (functionAtStart * functionAtPoint > 0) {
            start = point;
            functionAtStart = foo.value(start);
        } else {
            end = point;
            functionAtEnd = foo.value(end);
        }

        interval = interval/2;
        ittr++;
        point = (start + end) / 2;
    }

    return point;
}

double RootSolver::falsePositionMethod(double start, double end, double thrInterval, double thrFunction, int maxIttr) {
    if (start >= end) {
        throw std::invalid_argument("Beginning of interval is greater than the ending");
    }

    Function foo(this->expression_string);

    double root;
    double functionAtPoint;
    double functionAtStart;
    double functionAtEnd;
    double interval;
    double point;
    int ittr = 0;

    functionAtStart = foo.value(start);
    functionAtEnd = foo.value(end);

    if (functionAtStart * functionAtEnd > 0) {
        throw std::invalid_argument("Function does not change its sign between given interval");
    }

    interval = end - start;

    if (interval < thrInterval) {
        root = start;
    } else if (absoluteValue(functionAtStart) < thrFunction){
        root = start;
    } else if (absoluteValue(functionAtEnd) < thrFunction) {
        root = end;
    }

    while (1) {
        point = (start * functionAtEnd - end * functionAtStart) / (functionAtEnd - functionAtStart);
        
        functionAtPoint = foo.value(point);

        if (absoluteValue(functionAtPoint) < thrFunction || ittr >= maxIttr) {
            root = point;
            break;
        }

        if (functionAtStart * functionAtPoint > 0) {
            start = point;
            functionAtStart = foo.value(start);
        } else {
            end = point;
            functionAtEnd = foo.value(end);
        }

        interval = end - start;

        if (interval < thrInterval) {
            root = start;
            break;
        }

        ittr++;
    }

    return root;
}