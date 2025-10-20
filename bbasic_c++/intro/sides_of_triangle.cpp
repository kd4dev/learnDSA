#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"enter first side:";
    cin>>a;
    int b;
    cout<<"enter second side:";
    cin>>b;
    int c;
    cout<<"enter third side:";
    cin>>c;
    if((a + b > c) && (b + c > a) && (a + c > b))
    {
        cout<<"these are sides of the triangle";
    }
    else
    {
        cout<<"cant form a triangle";
    }
}