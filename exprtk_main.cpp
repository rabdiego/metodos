#include <iostream>
#include <string>
#include <stdexcept>

#include "exprtk.hpp"
#include "Function.h"

double absoluteValue(double a) {
    if (a >= 0) {
        return a;
    }
    return -a;
}

double bissectionMethod(std::string expression_string, double start, double end, double thr, int maxIttr) {
    if (start >= end) {
        throw std::invalid_argument("Beginning of interval is greater than the ending");
    }
    
    /*
    Parte para compilar a função

    Após a compilação, basta modificar o valor da variável x que está
    "linkada" à função, e chamar o método .value() para computar o valor
    da função no ponto.
    */

    /*
    typedef exprtk::symbol_table<double> symbol_table_d;
    typedef exprtk::expression<double>   expression_d;
    typedef exprtk::parser<double>       parser_d;

    double x;

    symbol_table_d symbol_table;
    symbol_table.add_variable("x",x);
    symbol_table.add_constants();

    expression_d expression;
    expression.register_symbol_table(symbol_table);

    parser_d parser;
    parser.compile(expression_string,expression);
    */
    Function foo(expression_string);

    /*
    Método da bissecção
    */

    //x = start;
    double functionAtStart = foo.value(start);
    //x = end;
    double functionAtEnd = foo.value(end);

    double functionAtPoint;

    if (functionAtStart * functionAtEnd > 0) {
        throw std::invalid_argument("Function does not change its sign between given interval");
    }

    double interval = end - start;
    int ittr = 0;
    double point = (start + end) / 2;

    while (interval > thr && ittr < maxIttr) {
        //x = point;
        functionAtPoint = foo.value(point);

        if (functionAtStart * functionAtPoint > 0) {
            start = point;
            //x = start;
            functionAtStart = foo.value(start);
        } else {
            end = point;
            //x = end;
            functionAtEnd = foo.value(end);
        }

        interval = interval/2;
        ittr++;
        point = (start + end) / 2;
    }

    return point;
}


int main()
{
    std::string expression_string;
    double start, end, thr, root;
    int maxIttr;
    char method;

    std::cout << "Function root solver by rabdiego" << std::endl << std::endl;

    std::cout << "Enter the function expression: ";
    std::getline(std::cin, expression_string);

    std::cout << "Enter the algorithm to solve this problem: " << std::endl;
    std::cout << "| Bissection Method: (B) | False Position Method: (F) |" << std::endl;
    std::cin >> method;

    switch (method) {
        case 'B':
            std::cout << "Enter the beginning of the interval: ";
            std::cin >> start;

            std::cout << "Enter the ending of the interval: ";
            std::cin >> end;

            std::cout << "Enter the tolerance of the algorithm: ";
            std::cin >> thr;

            std::cout << "Enter the maximum of iterations of the algorithm: ";
            std::cin >> maxIttr;

            root = bissectionMethod(expression_string, start, end, thr, maxIttr);

            break;
        
        default:
            throw std::invalid_argument("Method must be 'B' or 'F' char value");
            break;
    }

    std::cout << "The root is equal to " << root << std::endl;

    return 0;
}