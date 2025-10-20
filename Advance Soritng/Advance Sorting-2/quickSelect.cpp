#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int pivot = arr[(si + ei) / 2]; // Choose the middle element as the pivot
    int count = 0;

    // Count the number of elements less than or equal to the pivot
    for (int i = si; i <= ei; i++)
    { // Loop through the array from si to ei
        if (arr[i] <= pivot)
        {
            count++; // Increment count if the current element is <= pivot
        }
    }

    int pivotIdx = si + count - 1;           // Calculate the correct index for the pivot
    swap(arr[(si + ei) / 2], arr[pivotIdx]); // Move the pivot to its correct position

    int i = si; // Initialize the left pointer
    int j = ei; // Initialize the right pointer

    // Partition the array around the pivot
    while (i < pivotIdx && j > pivotIdx)
    { // Loop until the pointers cross
        if (arr[i] <= pivot)
        {
            i++; // Move the left pointer to the right if the element is <= pivot
        }
        else if (arr[j] > pivot)
        {
            j--; // Move the right pointer to the left if the element is > pivot
        }
        else
        {
            swap(arr[i], arr[j]); // Swap elements if they are out of place
            i++;                  // Move the left pointer
            j--;                  // Move the right pointer
        }
    }

    return pivotIdx; // Return the index of the pivot
}

int quickselect(int arr[], int si, int ei, int k)
{
    int pi = partition(arr, si, ei); // Partition the array and get the pivot index
    if (pi + 1 == k)
    { // If the pivot index + 1 equals k, we've found the k-th smallest element
        return arr[pi];
    }
    else if ((pi + 1) < k)
    { // If the pivot index + 1 is less than k, search the right partition
        return quickselect(arr, pi + 1, ei, k);
    }
    else
    { // If the pivot index + 1 is greater than k, search the left partition
        return quickselect(arr, si, pi - 1, k);
    }
}

int main()
{
    int arr[] = {5, 1, 8, 2, 7, 6, 3, 4, -8}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]);     // Calculate the size of the array
    int k = 4;                                // Find the 4th smallest element

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    { // Print the original array
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call quickselect to find the k-th smallest element and print it
    cout << "The " << k << "-th smallest element is: " << quickselect(arr, 0, n - 1, k) << endl;

    return 0;
}