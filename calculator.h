#pragma omce
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stack>
#include <string>

class Calculator
{
private:
    inline const bool isOperator(const char c) const
    {
        return (c == '+' || c == '-' || c == '*' ||
                c == '/' || c == '(' || c == ')');
    }

    const int getPrecedence(const char op) const;

    inline const bool hasHigherPrecedence(const char a, const char b) const { return getPrecedence(a) >= getPrecedence(b); }

    const double evaluate(const double a, const double b, const char op) const;

public:
    const std::string writeExpression() const;
    const std::string inToPostfix(const std::string &INFIX) const;
    const double calculate(const std::string &POSTFIX) const;
};

#endif // CALCULATOR_H