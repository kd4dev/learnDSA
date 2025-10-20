#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter a number:";
    cin>>n;
    bool flag = false; // true means prime
    for (int i=2;i<=n-1;i++) 
    {
        if(n%i==0) // i is factor of n
            flag=true;
            break;
    }
    if(n==1)
        cout<<"neither prime nor composite";
    if (flag == false) 
        cout<<"prime";
    else
        cout<<"composite";
}