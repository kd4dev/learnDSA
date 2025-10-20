#include<iostream>
 using namespace std;
 int main()
 {
     int n;
     cout<<"enter a number:";
     cin>>n;
     int product=1;
     for(int i=1;i<=n;i++)
       {
        product=product*i;
       }
    if(n==0)
        {
            cout<<1;
        }
    else
        {
            cout<<product;
        }
 }


