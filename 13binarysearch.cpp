// Binary Search algorithm to search an element in an array
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int a)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == a)
        {
            return m;
        }
        if (arr[m] < a)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    int n, a;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }
    cout << "Enter element to search for: ";
    cin >> a;
    int b = binarySearch(arr, n, a);
    if (b == -1)
    {
        cout << "Element not found." << endl;
    }
    else
    {
        cout << "Element found at index " << b << endl;
    }
    return 0;
}