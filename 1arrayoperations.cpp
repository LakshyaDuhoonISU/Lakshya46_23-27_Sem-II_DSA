// menu driven array operations program - 1.display array 2.insert at beginning 3.insert at end 4.insert before an element 5.insert after an element 6.delete at beginning 7.delete at end 8.delete before an element 9.delete after an element 10.search an element 11.number of elements
#include <iostream>
#include <algorithm>
using namespace std;

void displayArray(int &a, int arr[]) // function to display array and number of elements in array
{
    int count = 0;
    cout << "Array: ";
    for (int i = 0; i < a; i++)
    {
        if (arr[i] != -1)
        {
            cout << arr[i] << " ";
            count++;
        }
        else
        {
            break;
        }
    }
    cout << endl
         << "Number of elements: " << count << endl;
}

void insertAtBegin(int &a, int arr[]) // function to insert element at the beginning of the array
{
    if (a >= 45)
    {
        cout << "Array is full. Cannot insert at the beginning." << endl;
        return;
    }
    int b, count = 0;
    cout << "Enter beginning detail: ";
    cin >> b;
    for (int i = a - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = b;
    a++;
    for (int i = 0; i < a; i++)
    {
        if (arr[i] == -1)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertAtEnd(int &a, int arr[]) // function to insert element at the end of the array
{
    if (a >= 45)
    {
        cout << "Array is full. Cannot insert at the end." << endl;
        return;
    }
    int b, count = 0;
    cout << "Enter end detail: ";
    cin >> b;
    for (int i = 0; i < a; i++)
    {
        if (arr[i] == -1)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    arr[count] = b;
    count++;
    cout << "Size of array: " << count << endl;
    a = count;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertAtIndexLocation(int &c, int arr[]) // function to insert element at specified index location in the array
{
    int a, b;
    cout << "Enter updated detail: ";
    cin >> b;
    cout << "Enter index location: ";
    cin >> a;
    int i = c - 1;
    while (i >= a)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    c++;
    arr[a] = b;
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertBeforeElement(int &c, int arr[]) // function to insert element before specified element in the array
{
    int b, a, pos;
    cout << "Enter updated detail: ";
    cin >> b;
    cout << "Enter element to insert before: ";
    cin >> a;
    for (int i = 0; i < c; i++)
    {
        if (arr[i] == a)
        {
            pos = i;
        }
    }
    for (int i = c - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    c++;
    arr[pos] = b;
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertAfterElement(int &c, int arr[]) // function to insert element after specified element in the array
{
    int b, a, pos;
    cout << "Enter updated detail: ";
    cin >> b;
    cout << "Enter element to insert after: ";
    cin >> a;
    for (int i = 0; i < c; i++)
    {
        if (arr[i] == a)
        {
            pos = i;
        }
    }
    for (int i = c - 1; i > pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    c++;
    arr[pos + 1] = b;
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
}

void deleteFromBegin(int &c, int arr[]) // function to delete element from beginning of the array
{
    for (int i = 0; i < c; i++)
    {
        arr[i] = arr[i + 1];
    }
    c--;
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
}

void deleteFromEnd(int &c, int arr[]) // function to delete element from end of the array
{
    if (c <= 0)
    {
        cout << "Array is empty. Cannot delete from the end." << endl;
        return;
    }
    arr[c - 1] = arr[c];
    c--;
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
}

void deleteBeforeElement(int &c, int arr[]) // function to delete element before specified element in the array
{
    int b, pos;
    cout << "Enter element to delete after it: ";
    cin >> b;
    for (int i = 0; i < c; i++)
    {
        if (arr[i] == b)
        {
            pos = i;
        }
    }
    for (int i = pos - 1; i < c; i++)
    {
        arr[i] = arr[i + 1];
    }
    c--;
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
}

void deleteAfterElement(int &c, int arr[]) // function to delete element after specified element in the array
{
    int b, pos;
    cout << "Enter element to delete after it: ";
    cin >> b;
    for (int i = 0; i < c; i++)
    {
        if (arr[i] == b)
        {
            pos = i;
        }
    }
    for (int i = pos + 1; i < c; i++)
    {
        arr[i] = arr[i + 1];
    }
    c--;
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
}

void deleteFromArray(int &a, int arr[]) // function to delete elements from array
{
    int b, pos;
    cout << "Enter element to delete: ";
    cin >> b;
    for (int i = 0; i < a; i++)
    {
        if (arr[i] == b)
        {
            pos = i;
        }
    }
    for (int i = pos; i < a; i++)
    {
        arr[i] = arr[i + 1];
    }
    a--;
    for (int i = 0; i < a; i++)
    {
        cout << arr[i] << " ";
    }
}

void searchElement(int &a, int arr[]) // function to search an element in the array
{
    int b, count = 0;
    cout << "Enter element to search: ";
    cin >> b;
    for (int i = 0; i < a; i++)
    {
        if (arr[i] == b)
        {
            cout << "Element found at index " << i << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Element not found" << endl;
    }
}

int main()
{
    int arr[46], n, choice;
    fill_n(arr, 46, -1);
    cout << "Enter number of details you want to enter (less than 45): ";
    cin >> n;
    while (n >= 45 || n <= 0)
    {
        cout << "Invalid size. Enter a valid size" << endl;
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter detail: ";
        cin >> arr[i];
    }
    char ans = 'y';
    while (ans == 'y')
    {
        cout << "Enter your choice:\n1. Insert element at beginning\n2. Insert element at end\n3. Insert element at a particular index position\n4. Insert element before an element\n5. Insert element after an element\n6. Delete element from beginning\n7. Delete element from end\n8. Delete element before a particular element\n9. Delete element after a particular element\n10. Search an element\n11. Delete element from array\n12. Display array\n13. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertAtBegin(n, arr);
            break;
        case 2:
            insertAtEnd(n, arr);
            break;
        case 3:
            insertAtIndexLocation(n, arr);
            break;
        case 4:
            insertBeforeElement(n, arr);
            break;
        case 5:
            insertAfterElement(n, arr);
            break;
        case 6:
            deleteFromBegin(n, arr);
            break;
        case 7:
            deleteFromEnd(n, arr);
            break;
        case 8:
            deleteBeforeElement(n, arr);
            break;
        case 9:
            deleteAfterElement(n, arr);
            break;
        case 10:
            searchElement(n, arr);
            break;
        case 11:
            deleteFromArray(n, arr);
            break;
        case 12:
            displayArray(n, arr);
            break;
        case 13:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice\n";
        }
        cout << "Want to perform another operation? (y/n): ";
        cin >> ans;
    }
    return 0;
}