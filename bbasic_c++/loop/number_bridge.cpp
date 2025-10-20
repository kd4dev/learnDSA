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
        cout<<i;
    }
    cout<<endl;
    int nsp=1;
    int m=n-1; //new lines
    
    for(int i=1;i,i<=m;i++) // stars
    {   int a = 1;
        for(int j=1;j<=(m+1-i);j++)  
        {
            cout<<a;
            a++;
        }


        // spaces  
        for(int l=1;l<=nsp;l++)
        {
            cout<<" ";
        } nsp +=2;  
        a++;


        for(int j=1;j<=(m+1-i);j++)  
        {
            cout<<a;
            a++;
        }

        cout<<endl;      
    }
 }