// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"enter a number:";
//     cin>>n;
//     int last_digit;
//     if (n==0)
//     {
//         cout<<"0";
//     }
//     else
//     while(n>0)
//     {
//      last_digit=n%10;
//      cout<<last_digit;
//      n=n/10;
//     }
// }

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter a number:";
    cin>>n;
    int last_digit=0;
    int revrese=0;
    while(n>0)
    {
       revrese=revrese*10;
       last_digit=n%10;
       revrese=revrese+last_digit;
       n=n/10;
    }
    cout<<revrese;
    
}