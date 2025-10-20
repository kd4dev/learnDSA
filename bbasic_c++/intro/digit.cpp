#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"enter your number:";
    cin>>x;

    //if(999>=x>=100) 
    if(x>=100 && x<=999)
    {
        cout<<"it is a three digit number";
    }
    else
    {
        cout<<"it is not a three digit number";
    }
}