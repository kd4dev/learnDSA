#include <iostream>
using namespace std;
int main()
{
    //int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //  1 2 3
    //  4 5 6
    //  7 8 9
    // rowa -> 0-2
    // columns -> 0-2
    int m;
    cout<<"enter number of rows:";
    cin>>m;
    int n;
    cout<<"enter number of columns:";
    cin>>n;
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)   // same loops for input
        {
            cin >> arr[i][j] ;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)   // same loops for input
        {
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }

    //arr[0][0] = 4;
   //cout << arr[0][0];
}