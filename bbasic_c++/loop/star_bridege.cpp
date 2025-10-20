#include<iostream>
 using namespace std;
 int main()
 {
     int n;
    cout<<"enter a number:";
    cin>>n;
    // 2n-1 stars
    for(int i=1;i<=(2*n-1);i++)
    {
        cout<<"*";
    }
    cout<<endl;
    int nsp=1;
    int m=n-1; //new lines
    
    for(int i=1;i,i<=m;i++) // stars
    {
        for(int j=1;j<=(m+1-i);j++)  
        {
            cout<<"*";
        }
        // spaces  
        for(int l=1;l<=nsp;l++)
        {
            cout<<" ";
        } nsp +=2;  
        for(int j=1;j<=(m+1-i);j++)  
        {
            cout<<"*";
        }
        cout<<endl;  
    }
 }