#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"enter a number:";
    cin>>x;
    if(x % 5 == 0)
        if(x % 3 == 0)
            {
                cout<<"given number is divisible by 5 and 3";
            }
        else
        {
            cout<<"given number is divisible by 5 but not by 3";
        }    
    else
    {
        cout<<"given number is not divisible by 5 and 3 both";
    }    
}