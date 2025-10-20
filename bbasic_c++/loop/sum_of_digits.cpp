#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter a number:";
    cin>>n;
    int last_digit;
    int sum=0;
    while(n>0)
    {
       last_digit=n%10;
       sum=sum+last_digit;
       n=n/10;
    }
    cout<<sum;
    
}