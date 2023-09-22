#include "Function.h"

Function::Function() {
    
}

void Function::setString(std::string expression_string) {
    this->symbol_table.add_variable("x", this->x);
    this->symbol_table.add_constants();
    this->expression.register_symbol_table(this->symbol_table);
    this->parser.compile(expression_string, this->expression);
}

double Function::value(double x) {
    this->x = x;
    return this->expression.value();
}

double Function::derivativeValue(double x) {
    return (this->value(x + 1e-5) - this->value(x))/(1e-5);
}