#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    if(x % 5 == 0 || x % 3 == 0)
    {
        cout<<"given number is divisble by either 3 or 5";

    }
    else
    {
        cout<<"given number is not divisible by  3 and 5";
    }
}