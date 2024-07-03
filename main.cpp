#include <iostream>
#include <stack>
#include <string>

#include "calculator.h"

int main(void)
{
    Calculator calcu("(12 + 21) * (45 - 45 / 20) + 79");
    std::cout << "Result: " << calcu.getPostfix() << std::endl;

    return 0;
}