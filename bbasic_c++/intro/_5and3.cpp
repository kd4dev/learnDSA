#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"enter a number:";
    cin>>x;

    if(x % 5 == 0 && x % 3 == 0)
    {
        cout<<"given number is divisble by 5 and 3";
    }
    else
    {
        cout<<"given numer is not divisble by 5 and 3";
    }
}