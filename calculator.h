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
    inline const bool isOperator(const char c) const {
        return (c == '+' || c == '-' || c == '*' ||
                c == '/' || c == '(' || c == ')');
    }

    inline const int getPrecedence(const char op) const {
        switch (op) {
        case '(': return 3;          // ')' shall have the lowest precedence        
        case '*':                    // to ensure that that will be the ending of                    
        case '/': return 2;          // grouping enclosed by an opening parenthesis
        case '+':
        case '-': return 1;
        default:  return 0;
        }
    }

    inline const bool hasHigherPrecedence(const char a, const char b) { return getPrecedence(a) >= getPrecedence(b); }

    void inToPostfix(const std::string &INFIX);

    void calculate();

    const double evaluate(const double a, const double b, const char op) const;

public:
    Calculator(const std::string &INFIX) 
    {
        inToPostfix(INFIX);
        calculate();
    }

    const std::string getPostfix() const { return Postfix; }
    const double getResult() const { return Result; }
};

#endif // CALCULATOR_H