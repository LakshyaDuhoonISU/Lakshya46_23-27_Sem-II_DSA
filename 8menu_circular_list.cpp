// circular linked list menu
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

Node *createList(int n)
{
    Node *start = NULL;
    Node *ptr = start;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new Node();
        if (start == NULL)
        {
            start = newNode;
            ptr = newNode;
        }
        else
        {
            ptr->next = newNode;
            ptr = ptr->next;
        }
    }
    ptr->next = start;
    return start;
}

void searchElement(Node *&a)
{
    int element;
    cout << "Enter element to search: ";
    cin >> element;
    Node *ptr = a;
    Node *preptr = ptr;
    Node *temp = NULL;
    while (preptr->next != a)
    {
        if (ptr->data == element)
        {
            cout << "Element " << ptr->data << " found in node " << ptr << endl;
            temp = ptr;
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    if (temp == NULL)
    {
        cout << "No element found" << endl;
    }
}

void traverseList(Node *&a)
{
    int count = 0;
    Node *ptr = a;
    Node *preptr = ptr;
    cout << "Circular Linked List: " << endl;
    while (preptr->next != a)
    {
        cout << ptr->data << endl;
        preptr = ptr;
        ptr = ptr->next;
        count++;
    }
    cout << "Number of nodes: " << count << endl;
}

void insertAtBegin(Node *&a)
{
    Node *ptr = a;
    Node *newNode = new Node();
    if (newNode == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    newNode->next = a;
    while (ptr->next != a)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    a = newNode;
}

void insertAtEnd(Node *&a)
{
    Node *ptr = a;
    Node *newNode = new Node();
    if (newNode == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    newNode->next = a;
    while (ptr->next != a)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void insertBeforeElement(Node *&a)
{
    Node *ptr = a;
    Node *preptr = a;
    Node *newNode = new Node();
    if (newNode == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        int element;
        cout << "Enter element to insert a node before it: ";
        cin >> element;
        if (ptr->data == element)
        {
            newNode->next = a;
            while (ptr->next != a)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            a = newNode;
            return;
        }
        else
        {
            do
            {
                if (ptr->data == element)
                {
                    preptr->next = newNode;
                    newNode->next = ptr;
                    return;
                }
                preptr = ptr;
                ptr = ptr->next;
            } while (ptr != a);
            if (ptr == a)
            {
                cout << "Element not found" << endl;
                return;
            }
        }
    }
}

void insertAfterElement(Node *&a)
{
    Node *ptr = a;
    Node *preptr = ptr;
    Node *newNode = new Node();
    if (newNode == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        int element;
        cout << "Enter element to insert a node after it: ";
        cin >> element;
        do
        {
            if (preptr->data == element)
            {
                if (preptr == a)
                {
                    newNode->next = a->next;
                    a->next = newNode;
                    return;
                }
                if (preptr->next == a)
                {
                    preptr->next = newNode;
                    newNode->next = a;
                    a = newNode;
                    return;
                }
                preptr->next = newNode;
                newNode->next = ptr;
                return;
            }
            preptr = ptr;
            ptr = ptr->next;
        } while (ptr != a);
        if (ptr == a)
        {
            cout << "Element not found" << endl;
            return;
        }
    }
}

void deleteAtBegin(Node *&a)
{
    Node *ptr = a;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    while (ptr->next != a)
    {
        ptr = ptr->next;
    }
    Node *temp = a;
    ptr->next = temp->next;
    a = temp->next;
    delete temp;
}

void deleteAtEnd(Node *&a)
{
    Node *ptr = a;
    Node *preptr = ptr;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    while (ptr->next != a)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = a;
    delete ptr;
}

void deleteBeforeElement(Node *&a)
{
    int element;
    cout << "Enter element to delete node before it: ";
    cin >> element;
    Node *ptr = a;
    Node *preptr = NULL;
    Node *temp = NULL;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        if (element == a->data)
        {
            cout << "Cannot delete before first element" << endl;
            return;
        }
        else
        {
            do
            {
                if (ptr->data == element)
                {
                    if (temp == NULL)
                    {
                        ptr = a;
                        while (ptr->next != a)
                        {
                            ptr = ptr->next;
                        }
                        temp = a;
                        ptr->next = temp->next;
                        a = temp->next;
                        delete temp;
                        return;
                    }
                    temp->next = ptr;
                    delete preptr;
                }
                temp = preptr;
                preptr = ptr;
                ptr = ptr->next;
            } while (ptr != a);
            return;
            if (ptr == a)
            {
                cout << "Element not found" << endl;
                return;
            }
        }
    }
}

void deleteAfterElement(Node *&a)
{
    int element;
    cout << "Enter element to delete node after it: ";
    cin >> element;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    Node *ptr = a;
    Node *preptr = NULL;
    do
    {
        if (ptr->data == element)
        {
            if (ptr->next == a)
            {
                Node *temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
                a = ptr->next;
                return;
            }
            else
            {
                preptr = ptr;
                ptr = ptr->next;
                preptr->next = ptr->next;
                delete ptr;
                return;
            }
        }
        preptr = ptr;
        ptr = ptr->next;
    } while (ptr != a);
    return;
    cout << "Element not found" << endl;
}

void deleteList(Node *&a)
{
    Node *ptr = a;
    Node *preptr = ptr;
    while (ptr->next != a)
    {
        preptr = ptr;
        ptr = ptr->next;
        delete preptr;
    }
    a = NULL;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *start = createList(n);
    int choice;
    char ans = 'y';
    do
    {
        cout << "Enter your choice: \n1.Insert a node at beginning\n2.Insert a node at end\n3.Search the list for an element\n4.Insert a node after an element\n5.Insert a node before an element\n6.Delete first node\n7.Delete last node\n8.Delete a node after a particular element\n9.Delete a node before a particular element\n10.Show list\n11.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertAtBegin(start);
            break;
        case 2:
            insertAtEnd(start);
            break;
        case 3:
            searchElement(start);
            break;
        case 4:
            insertAfterElement(start);
            break;
        case 5:
            insertBeforeElement(start);
            break;
        case 6:
            deleteAtBegin(start);
            break;
        case 7:
            deleteAtEnd(start);
            break;
        case 8:
            deleteAfterElement(start);
            break;
        case 9:
            deleteBeforeElement(start);
            break;
        case 10:
            traverseList(start);
            break;
        case 11:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Wrong choice" << endl;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ans;
    } while (ans == 'y');
    deleteList(start);
    return 0;
}