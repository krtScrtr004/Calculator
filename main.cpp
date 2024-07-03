#include <iostream>
#include <stack>
#include <string>

#include "calculator.h"

int main(void)
{
    // FIXME (56 * 45) / (56.23 - 45 + 84.12 * (45 / 69)) - 15.12
    Calculator calcu("((56*45)/(56.23-45+(84.12*(45/69))))-15.12");
    std::cout << "Result: " << calcu.getResult() << std::endl;

    return 0;
}