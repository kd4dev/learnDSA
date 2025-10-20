#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"enter first number:";
    cin>>x;
    int y;
    cout<<"enter second number:";
    cin>>y;
    int z;
    cout<<"enter third number:";
    cin>>z;
    if(x > y && x > z)
    cout<<x;
    else if(y > z && y > x)
    {
        cout<<y;
    }
    else
    {
        cout<<z;
    }
}