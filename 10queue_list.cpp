// queue menu driven program(linked list)
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        cout << "Enter data: ";
        cin >> data;
        next = NULL;
    }
};

void enqueue(Node *&start, Node *&end)
{
    Node *newnode = new Node();
    if (start == NULL)
    {
        start = newnode;
        end = newnode;
    }
    else
    {
        end->next = newnode;
        end = newnode;
    }
    cout << "Element added successfully.\n";
}

void dequeue(Node *&start, Node *&end)
{
    Node *ptr = NULL;
    if (start == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }
    else
    {
        ptr = start;
        start = start->next;
        cout << "Element " << ptr->data << " deleted successfully.\n";
        delete ptr;
    }
}

void peek(Node *&start)
{
    if (start == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }
    else
    {
        cout << "Top element: " << start->data << endl;
    }
}

void deleteQueue(Node *&start)
{
    Node *ptr = start;
    Node *temp = NULL;
    if (start == NULL)
    {
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }
    start = NULL;
}

void showQueue(Node *start)
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    Node *front = NULL;
    Node *rear = NULL;
    int choice;
    while (true)
    {
        cout << "\nQueue Operations:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enqueue(front, rear);
            break;
        case 2:
            dequeue(front, rear);
            break;
        case 3:
            peek(front);
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