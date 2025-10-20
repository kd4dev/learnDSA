#include <iostream>
#include<climits>
using namespace std;
int main()
{
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
    // MAX
    int max = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)   // same loops for input
        {
            if(max<arr[i][j]) max=arr[i][j];
        }
    } 
    cout<<max;  
}