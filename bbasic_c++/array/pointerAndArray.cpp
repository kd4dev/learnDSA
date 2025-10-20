#include <iostream>
using namespace std;
int main()
{
    int arr[] = {4, 2, 6, 1, 7};
    int *ptr = arr;
    for (int i = 0; i <= 4; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }
    ptr = arr;
    *ptr = 8;
    ptr++;
    *ptr = 9;
    ptr--;
    cout << endl;
    for (int i = 0; i <= 4; i++)
    {
        cout << *ptr << " "; //cout<<i[arr] or cout<<i[ptr]
        ptr++;
    }
    ptr = arr;
}