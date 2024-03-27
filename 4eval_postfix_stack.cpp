// evaluating postfix expression using stack(array)
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string expression;
    char stack[100];
    int stack1[100];
    int top = -1, a, b, result = 0;
    cout << "Enter postfix expression: ";
    getline(cin, expression);
    for (int i = 0; i < expression.length(); i++)
    {
        stack[i] = expression[i];
    }
    stack[expression.length()] = ')';
    int i = 0;
    while (stack[i] != ')')
    {
        if (stack[i] == '*' || stack[i] == '/' || stack[i] == '%' || stack[i] == '-' || stack[i] == '+')
        {
            a = stack1[top];
            top--;
            b = stack1[top];
            top--;
            if (stack[i] == '*')
            {
                result = b * a;
            }
            else if (stack[i] == '/')
            {
                if (a != 0)
                {
                    result = b / a;
                }
                else
                {
                    cout << "Error: Division by zero." << endl;
                    return 1;
                }
            }
            else if (stack[i] == '%')
            {
                result = b % a;
            }
            else if (stack[i] == '+')
            {
                result = b + a;
            }
            else
            {
                result = b - a;
            }
            top++;
            stack1[top] = result;
        }
        else
        {
            top++;
            stack1[top] = int(stack[i]) - 48;
        }
        i++;
    }
    cout << "Result: " << stack1[top] << endl;
    return 0;
}