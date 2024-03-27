// stack operations(array)
#include <iostream>
using namespace std;

int main()
{
    int top = -1, element, op,n;
    cout<<"Enter size of stack: ";
    cin>>n;
    int stack[n];
    while (true)
    {
        cout << "\nStack operation:\n1.Push\n2.Pop\n3.Peek\n4.Exit\n";
        cin >> op;
        switch (op)
        {
        case 1:
            if (top == n - 1)
            {
                cout << "Stack is full. Cannot add more elements.\n";
                break;
            }
            else
            {
                cout << "Enter element: ";
                cin >> element;
                top++;
                stack[top] = element;
                cout << "Element added in stack\n";
            }
            break;
        case 2:
            if (top == -1)
            {
                cout << "Stack is empty.\n";
                break;
            }
            else
            {
                cout << stack[top] << " is popped from stack\n";
                top--;
            }
            break;
        case 3:
            if (top == -1)
            {
                cout << "Stack is empty.\n";
                break;
            }
            else
            {
                cout << "Top element: " << stack[top] << "\n";
            }
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Wrong choice\n";
            break;
        }
    }
    return 0;
}