#include "calculator.h"

const int Calculator::getPrecedence(const char op) const
{
    switch (op)
    {
    case '(':
        return 3; 
    case '*':     
    case '/':
        return 2; 
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

const std::string Calculator::writeExpression() const
{
    std::string expression = "";
    while (true)
    {
        std::cout << "Enter expression: ";
        std::getline(std::cin, expression);

        if (expression.empty())
        {
            std::cerr << "Error: expression is empty" << std::endl;
            continue;
        }

        if (expression.length() < 1 || expression.length() > 100)
        {
            std::cerr << "Error: expression length should be between 1 and 100 characters" << std::endl;
            continue;
        }

        break;
    }

    return expression;
}

const std::string Calculator::inToPostfix(const std::string &INFIX) const
{
    std::string postfix = "";
    std::stack<char> stk;

    for (std::size_t i = 0, n = INFIX.size(); i < n; ++i)
    {
        if (std::isdigit(INFIX[i]) || INFIX[i] == '.')
        {
            while (i < INFIX.size() && (std::isdigit(INFIX[i]) || INFIX[i] == '.'))
            {
                postfix += INFIX[i];
                ++i;
            }
            postfix += ' ';
            --i;
        }
        else if (INFIX[i] == '(')
        {
            stk.push(INFIX[i]);
        }
        else if (INFIX[i] == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                postfix += stk.top();
                postfix += ' ';
                stk.pop();
            }
            if (!stk.empty() && stk.top() == '(')
                stk.pop();
        }
        else if (isOperator(INFIX[i]))
        {
            while (!stk.empty() && stk.top() != '(' && hasHigherPrecedence(stk.top(), INFIX[i]))
            {
                postfix += stk.top();
                postfix += ' ';
                stk.pop();
            }
            stk.push(INFIX[i]);
        }
    }

    while (!stk.empty())
    {
        if (stk.top() != '(' && stk.top() != ')')
        {
            postfix += stk.top();
            postfix += ' ';
        }
        stk.pop();
    }

    return postfix;
}

const double Calculator::calculate(const std::string &POSTFIX) const
{
    std::stack<double> stk;
    for (std::size_t i = 0, n = POSTFIX.size(); i < n; ++i)
    {
        if (POSTFIX[i] == ' ')
            continue;

        if (!isOperator(POSTFIX[i]))
        {
            std::string operand = "";
            while (i < n && !isOperator(POSTFIX[i]) && POSTFIX[i] != ' ')
            {
                operand += POSTFIX[i];
                i++;
            }
            stk.push(std::stod(operand));
        }
        else
        {
            if (stk.size() == 1)
                break;

            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            stk.push(evaluate(a, b, POSTFIX[i]));
        }
    }

    return stk.top();
}

const double Calculator::evaluate(const double a, const double b, const char op) const
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return b - a;
    case '*':
        return a * b;
    case '/':
        if (a == 0)
            throw std::runtime_error("Error: Division by zero.");
        return b / a;
    default:
        throw std::runtime_error("Error: Invalid operator!");
    }

    return 0.0;
}
