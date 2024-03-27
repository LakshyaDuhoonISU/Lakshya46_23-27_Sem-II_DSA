// circular queue menu driven operations(array)
#include <iostream>
using namespace std;
int main()
{
    int element, front = -1, rear = -1, n, choice;
    cout << "Enter size of queue: ";
    cin >> n;
    int queue[n];
    while (true)
    {
        cout << "\nCircular queue operations:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if ((front == 0 && rear == n - 1) || rear == front - 1)
            {
                cout << "Queue is full. Cannot add more elements.\n";
            }
            else
            {
                if (rear == n - 1 && front != 0)
                {
                    rear = (rear + 1) % n;
                }
                else if (front == -1 && rear == -1)
                {
                    front++;
                    rear++;
                }
                else
                {
                    rear++;
                }
                cout << "Enter element: ";
                cin >> element;
                queue[rear] = element;
                cout << "Element added successfully.\n";
            }
            break;
        case 2:
            if (front == -1)
            {
                cout << "Queue is empty. Cannot delete elements.\n";
            }
            else
            {
                element = queue[front];
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else if (front == n - 1)
                {
                    front = (front + 1) % n;
                }
                else
                {
                    front++;
                }
                cout << "Element " << element << " is popped from the queue.\n";
            }
            break;
        case 3:
            if (front == -1)
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Top element: " << queue[front] << endl;
            }
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Wrong input\n";
            break;
        }
    }
    return 0;
}