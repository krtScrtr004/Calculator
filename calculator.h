#pragma omce
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stack>
#include <string>

class Calculator
{
private:
    std::string Postfix;
    double Result;

private:
    inline const bool isOperator(const char c) const
    {
        return (c == '+' || c == '-' || c == '*' ||
                c == '/' || c == '(' || c == ')');
    }

    inline const int getPrecedence(const char op) const
    {
        switch (op)
        {
        case '(':           // ')' shall have the lowest precedence
            return 3;       // to ensure that that will be the ending of
        case '*':           // grouping enclosed by an opening parenthesis
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
        }
    }

    inline const bool hasHigherPrecedence(const char a, const char b) { return getPrecedence(a) > getPrecedence(b); }

    void inToPostfix(const std::string &INFIX);

    void calculate();

public:
    Calculator(const std::string &INFIX) 
    {
        inToPostfix(INFIX);
    }

    const std::string getPostfix() const { return Postfix; }
};

#endif // CALCULATOR_H