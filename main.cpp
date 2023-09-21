#include <iostream>
#include <string>
#include <stdexcept>

#include "RootSolver.h"

int main()
{
    std::string expression_string;
    double start, end, thr, thr2, root;
    int maxIttr;
    char method;

    RootSolver solver;

    std::cout << "Function root solver by rabdiego" << std::endl << std::endl;

    std::cout << "Enter the function expression: ";
    std::getline(std::cin, expression_string);
    solver.setString(expression_string);

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

            root = solver.bissectionMethod(start, end, thr, maxIttr);

            break;

        case 'F':
            std::cout << "Enter the beginning of the interval: ";
            std::cin >> start;

            std::cout << "Enter the ending of the interval: ";
            std::cin >> end;

            std::cout << "Enter the interval tolerance of the algorithm: ";
            std::cin >> thr;

            std::cout << "Enter the function tolerance of the algorithm: ";
            std::cin >> thr2;

            std::cout << "Enter the maximum of iterations of the algorithm: ";
            std::cin >> maxIttr;

            root = solver.falsePositionMethod(start, end, thr, thr2, maxIttr);

            break;
        
        default:
            throw std::invalid_argument("Method must be 'B' or 'F' char value");
            break;
    }

    std::cout << "The root is equal to " << root << std::endl;

    return 0;
}