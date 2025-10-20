#include<iostream>
using namespace std;
int main(){
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
    cout<<endl;

    //store transpose
    int t[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)   // same loops for input
        {
            t[i][j]= arr[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)   // same loops for input
        {
            cout << t[i][j] << " ";
        }
        cout<<endl;
    }
}