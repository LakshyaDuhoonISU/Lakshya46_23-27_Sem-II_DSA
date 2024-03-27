// menu driven linked list
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

Node *createList(int n) // function to create a linked list
{
    Node *start = NULL;
    Node *ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *new_node = new Node();
        if (start == NULL)
        {
            start = new_node;
            ptr = start;
        }
        else
        {
            ptr->next = new_node;
            ptr = new_node;
        }
    }
    return start;
}

void insertAtStart(Node *&a) // function to insert a node at the start of list
{
    Node *new_node = new Node();
    if (new_node == NULL)
    {
        cout << "Overflow";
        return;
    }
    else
    {
        new_node->next = a;
        a = new_node;
    }
}

void insertAtEnd(Node *&a) // function to insert a node at the end of list
{
    Node *new_node = new Node();
    Node *ptr = a;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
}

void insertAfterElement(Node *&a) // function to insert a node after a particular element in the list
{
    int n;
    cout << "Enter element after which to add a node: ";
    cin >> n;
    Node *new_node = new Node();
    Node *ptr = a;
    Node *preptr = ptr;
    if (new_node == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        while (preptr->data != n)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "No element found" << endl;
        }
        else if (ptr == a)
        {
            new_node->next = ptr->next;
            a->next = new_node;
        }
        else
        {
            new_node->next = ptr;
            preptr->next = new_node;
        }
    }
}

void insertBeforeElement(Node *&a) // function to insert a node before a particular element in the list
{
    Node *ptr = a;
    Node *preptr = ptr;
    int b;
    cout << "Enter element to add a node before it: ";
    cin >> b;
    Node *new_node = new Node();
    if (new_node == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        while (ptr->data != b)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            cout << "No element found" << endl;
        }
        else if (ptr == a)
        {
            new_node->next = ptr;
            a = new_node;
        }
        else
        {
            preptr->next = new_node;
            new_node->next = ptr;
        }
    }
}

void deleteFirstNode(Node *&a) // function to delete the first node in the list
{
    Node *ptr = a;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        a = ptr->next;
        delete ptr;
    }
}

void deleteLastNode(Node *&a) // function to delete the last node in the list
{
    Node *ptr = a;
    Node *preptr = ptr;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (preptr == ptr) // if there is only one node, delete it and make the start pointer NULL
        {
            delete ptr;
            a = NULL;
        }
        else
        {
            preptr->next = NULL;
            delete ptr;
        }
    }
}

void deleteBeforeElement(Node *&a) // function to delete the node before a particular element in the list
{
    Node *ptr = a;
    Node *preptr = NULL;
    Node *temp = a;
    int b;
    cout << "Enter element to delete a node before it: ";
    cin >> b;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        while (ptr->data != b)
        {
            temp = preptr;
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "Element not found" << endl;
                return;
            }
        }
        if (preptr == NULL) // if first node is selected, print error message
        {
            cout << "Element not found" << endl;
        }
        else
        {
            if (preptr == a)
            {
                a = ptr;
            }
            else
            {
                temp->next = ptr;
            }
            delete preptr;
        }
    }
}

void deleteAfterElement(Node *&a) // function to delete the node after a particular element in the list
{
    Node *ptr = a;
    Node *preptr = a;
    Node *temp = NULL;
    int b;
    cout << "Enter element to delete node after: ";
    cin >> b;
    ptr = a;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        while (ptr->data != b)
        {
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "Element not found" << endl;
                return;
            }
        }
        if (ptr == NULL)
        {
            cout << "Element not found" << endl;
        }
        else
        {
            if (ptr->next == NULL)
            {
                cout << "No element to delete" << endl;
            }
            else
            {
                preptr = ptr;
                temp = ptr->next;
                preptr->next = temp->next;
                delete temp;
            }
        }
    }
}

void searchElement(Node *a, int b) // function to search for a particular element in the list
{
    Node *ptr = a;
    Node *pos = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == b)
        {
            pos = ptr;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    if (pos == NULL)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element " << pos->data << " found at " << pos << endl;
    }
}

void showList(Node *a) // function to display the list and print number of nodes in the list
{
    int count = 0;
    Node *ptr = a;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
        count++;
    }
    cout << endl
         << "Number of nodes: " << count << endl;
}

void deleteList(Node *&a) // function to delete the list
{
    Node *ptr = a;
    Node *temp = NULL;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
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
            insertAtStart(start);
            break;
        case 2:
            insertAtEnd(start);
            break;
        case 3:
            int element;
            cout << "Enter the element to search for: ";
            cin >> element;
            searchElement(start, element);
            break;
        case 4:
            insertAfterElement(start);
            break;
        case 5:
            insertBeforeElement(start);
            break;
        case 6:
            deleteFirstNode(start);
            break;
        case 7:
            deleteLastNode(start);
            break;
        case 8:
            deleteAfterElement(start);
            break;
        case 9:
            deleteBeforeElement(start);
            break;
        case 10:
            showList(start);
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