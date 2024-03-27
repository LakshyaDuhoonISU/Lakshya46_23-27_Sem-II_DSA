// conversion of infix to postfix expression using stack(array)
#include <iostream>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string exp, result = "";
    char stack[100];
    int top = -1;
    cout << "Enter infix expression: ";
    getline(cin, exp);
    int n = exp.length();
    char express[n + 2];
    express[0] = '(';
    for (int i = 0; i < n; i++)
    {
        express[i + 1] = exp[i];
    }
    express[n + 1] = ')';
    for (int i = 0; i < n + 2; i++)
    {
        if (express[i] == '(')
        {
            top++;
            stack[top] = express[i];
        }
        else if (express[i] == ')')
        {
            while (stack[top] != '(' && top > -1)
            {
                result += stack[top];
                top--;
            }
            top--;
        }
        else if ((express[i] >= 'a' && express[i] <= 'z') || (express[i] >= 'A' && express[i] <= 'Z') || (express[i] >= '0' && express[i] <= '9'))
        {
            result += express[i];
        }
        else
        {
            while (top > -1 && precedence(stack[top]) >= precedence(express[i]))
            {
                result += stack[top];
                top--;
            }
            top++;
            stack[top] = express[i];
        }
    }
    while (top > -1)
    {
        result += stack[top];
        top--;
    }
    cout << "Postflix Result: " << result << endl;
    return 0;
}