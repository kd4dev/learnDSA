#include <iostream>
using namespace std;
int main()
{
   
    
    int arr[2][4];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)   // same loops for input
        {
            cin >> arr[i][j] ;  
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)   // same loops for input
        {
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }

    
}