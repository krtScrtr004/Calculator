#include "calculator.h"

void Calculator::inToPostfix(const std::string &INFIX)
{
    std::string postfix = "";
    std::stack<char> stk;

    for (std::size_t i = 0, n = INFIX.size(); i < n; ++i)
    {
        while (i < n && !isOperator(INFIX[i]))
        {
            postfix += INFIX[i];
            ++i;
        }

        if (isOperator(INFIX[i]))
        {
            while (!stk.empty() && stk.top() != '(' &&              // stk.top() != '(' ensures that the '('
                   hasHigherPrecedence(stk.top(), INFIX[i]))        // will not be popped out into the stack
            {                                                       // before ')' character is encountered         
                postfix += stk.top();

                stk.pop();
                if (!stk.empty() && (stk.top() == '(' || stk.top() == ')'))
                    stk.pop();
            }
            stk.push(INFIX[i]);
        }
    }

    // Append the remaining operators
    while (!stk.empty())
    {
        if (stk.top() != '(' && stk.top() != ')')
            postfix += stk.top();
        stk.pop();
    }

    Postfix = postfix;
}

// void Calculator::calculate()
// {

// }
