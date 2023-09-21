#include <string>
#include "exprtk.hpp"

#ifndef Function_H
#define Function_H

class Function {
public:
    double x;

    exprtk::symbol_table<double> symbol_table;
    exprtk::expression<double> expression;
    exprtk::parser<double> parser;

    Function(std::string expression_string);
    double value(double x);
};

#endif