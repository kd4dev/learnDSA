#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int pivot = arr[(si + ei) / 2]; // Line 5: Choose the middle element as the pivot
    int count = 0;

    // Count the number of elements less than or equal to the pivot
    for (int i = si; i <= ei; i++) { // Line 8: Loop to count elements <= pivot
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIdx = si + count - 1; // Line 13: Correct pivot index calculation
    swap(arr[(si + ei) / 2], arr[pivotIdx]); // Line 14: Move pivot to its correct position

    int i = si; // Line 16: Initialize `i` correctly
    int j = ei; // Line 17: Initialize `j` correctly

    // Partition the array around the pivot
    while (i < pivotIdx && j > pivotIdx) { // Line 19: Partitioning logic
        if (arr[i] <= pivot) {
            i++;
        } else if (arr[j] > pivot) {
            j--;
        } else {
            swap(arr[i], arr[j]); // Line 24: Swap elements
            i++;
            j--;
        }
    }

    return pivotIdx; // Line 28: Return the correct pivot index
}

void quicksort(int arr[], int si, int ei)
{
    if (si >= ei) // Line 32: Base case
        return;

    int pi = partition(arr, si, ei); // Line 35: Partition the array
    quicksort(arr, si, pi - 1); // Line 36: Sort left partition
    quicksort(arr, pi + 1, ei); // Line 37: Sort right partition
}

int main()
{
    int arr[] = {5, 1, 8, 2, 7, 6, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) { // Line 44: Print original array
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1); // Line 48: Call quicksort

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) { // Line 50: Print sorted array
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}