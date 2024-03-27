// queue menu driven program(array)
#include <iostream>
using namespace std;
int main()
{
    int front = -1, rear = -1, choice, element, n;
    cout << "Enter size of queue: ";
    cin >> n;
    int queue[n];
    while (true)
    {
        cout << "\nQueue Operation:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (rear == n - 1)
            {
                cout << "Queue is full. Cannot add more elements.\n";
            }
            else
            {
                cout << "Enter element: ";
                cin >> element;
                if (front == -1 && rear == -1)
                {
                    front = 0, rear = 0;
                }
                else
                {
                    rear++;
                }
                queue[rear] = element;
                cout << "Element added successfully.\n";
            }
            break;
        case 2:
            if (front == -1 || front > rear)
            {
                cout << "Queue is empty. Cannot delete more elements.\n";
            }
            else
            {
                element = queue[front];
                front++;
                cout << "Element " << element << " removed successfully.\n";
            }
            break;
        case 3:
            if (front == -1 || rear == -1 || front > rear)
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Front element: " << queue[front] << endl;
            }
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Wrong choice.\n";
            break;
        }
    }
    return 0;
}