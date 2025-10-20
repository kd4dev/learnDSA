#include<iostream>
 using namespace std;
 int main()
 {
    int n;
    cout<<"number of rows:";
    cin>>n;
    // number of stars=n + 1 - i
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n + 1 - i;j++)
        {
            cout<<"*";
        }
        cout<<endl; 
    }
 }