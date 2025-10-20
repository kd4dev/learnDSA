#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"enter a number:";
    cin>>x;
   // if((x % 5 == 0 || x % 3 == 0) && (x % 15 != 0))
   if((x % 5 == 0 || x % 3 == 0))
        if((x % 15 != 0))  
         {
        cout<<"given number is divisible by 5 or 3 but not divisible by 15";
         }
        else 
         {
        cout<<"it is divisible by 15";
         }
 else 
   {
        cout<<"it is not divisible by 15";
   }  
    
}