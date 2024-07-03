#include "calculator.h"

void Calculator::inToPostfix(const std::string &INFIX) {
    std::string postfix;
    std::stack<char> stk;

    for (std::size_t i = 0, n = INFIX.size(); i < n; ++i) {
        if (std::isdigit(INFIX[i]) || INFIX[i] == '.') {
            while (i < INFIX.size() && (std::isdigit(INFIX[i]) || INFIX[i] == '.')) {
                postfix += INFIX[i];
                ++i;
            }
            postfix += ' ';
            --i; 
        } else if (INFIX[i] == '(') {
            stk.push(INFIX[i]);
        } else if (INFIX[i] == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                postfix += ' ';
                stk.pop();
            }
            if (!stk.empty() && stk.top() == '(') 
                stk.pop();
        } else if (isOperator(INFIX[i])) {
            while (!stk.empty() && stk.top() != '(' && hasHigherPrecedence(stk.top(), INFIX[i])) {
                postfix += stk.top();
                postfix += ' ';
                stk.pop();
            }
            stk.push(INFIX[i]);
        }
    }

    // Append remaining operators in the stack
    while (!stk.empty()) {
        if (stk.top() != '(' && stk.top() != ')') {
            postfix += stk.top();
            postfix += ' ';
        }
        stk.pop();
    }

    // Assign the final postfix expression
    Postfix = postfix;
}

void Calculator::calculate() {
    std::stack<double> stk;

    for (std::size_t i = 0, n = Postfix.size(); i < n; ++i) {
        if (Postfix[i] == ' ') continue;

        if (!isOperator(Postfix[i])) {
            std::string operand = "";
            while (i < n && !isOperator(Postfix[i]) && Postfix[i] != ' ') {
                operand += Postfix[i];
                i++;
            }
            stk.push(std::stod(operand));
        } else {
            if (stk.size() == 1) {
                Result = stk.top();
                break;
            }
            
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            stk.push(evaluate(a, b, Postfix[i]));
        }
    }

    if (stk.size() == 1)
        Result = stk.top();
    else   
        std::cout << "Stack has more than 1 elements" << std::endl;
}

const double Calculator::evaluate(const double a, const double b, const char op) const
{
    switch (op) {
        case '+': return a + b;
        case '-': return b - a;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Error: Division by zero.");
            return b / a;
        default:
            throw std::runtime_error("Error: Invalid operator!");
    }

    return 0.0;
}
