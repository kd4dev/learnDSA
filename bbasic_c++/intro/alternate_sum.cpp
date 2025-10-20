// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"enter a number:";
//     cin>>n;
//     int sum=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(i%2!=0)
//         sum =i+sum;
//         else
//         sum=sum-i;
//     }
//     cout<<sum;
// }
#include<iostream>
 using namespace std;
 int main()
 {
     int n;
     cout<<"enter a number:";
     cin>>n;
     if(n % 2 == 0)
        {
            cout<<(n/2)*(-1);
        }
     else
        {
            cout<<(((n/2)*(-1))+n);
        }
 }