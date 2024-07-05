#include <iostream>
#include <istream>
#include <limits>
#include <stack>
#include <string>

#include "calculator.h"

enum class OPTIONS : unsigned int
{
    CALCULATE = 1,
    EXIT
};

std::istream &operator>>(std::istream &is, OPTIONS &option)
{
    unsigned int input;
    is >> input;
    option = static_cast<OPTIONS>(input);
    return is;
}

int main(void)
{
    while (true)
    {
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "CALCULATOR USING STACK DATA STRUCTURE" << std::endl;

        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "Choose an option: " << std::endl;
        std::cout << "[1] Calculate" << std::endl;
        std::cout << "[2] Exit" << std::endl;

        std::cout << "---------------------------------------------------------" << std::endl;
        OPTIONS option;
        bool isValid = false;
        do
        {
            std::cout << "Enter your choice (1-2): ";
            std::cin >> option;
            if (option == OPTIONS::CALCULATE || option == OPTIONS::EXIT)
                isValid = true;
        } while (!isValid);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (option == OPTIONS::EXIT)
            break;
        std::cout << "---------------------------------------------------------" << std::endl;

        Calculator calculator;
        const std::string EXPRESSION = calculator.writeExpression();
        std::cout << "---------------------------------------------------------" << std::endl;
        const std::string POSTFIX = calculator.inToPostfix(EXPRESSION);
        std::cout << "Result: " << calculator.calculate(POSTFIX) << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;

        std::cout << std::endl;
    }

    return 0;
}