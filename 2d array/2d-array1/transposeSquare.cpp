#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"enter number of rows/column:";
    cin>>m;
    
    int arr[m][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)   // same loops for input
        {
            cin >> arr[i][j] ;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)   // same loops for input
        {
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;

    // transpose in same matrix
   
    for (int i = 1; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)   // same loops for input
        {   
           // if(i>j){} ye krke direct ho jayega loop me badal krne ki jarurat nahi he
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)   // same loops for input
        {
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }
}