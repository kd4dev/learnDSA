#include<iostream>
 using namespace std;
 int main()
 {
     int a;
     cout<<"enter base:";
     cin>>a;
     int b;
     cout<<"exponent:";
     cin>>b;
     bool flag = true; //true means exponent positive
     if(b<0)
     {
        flag = false;
        b = -b;
     }
     float power = 1;
        for(int i=1;i<=b;i++)
         {
           power=power*a;
        }
            if(flag==false)
                {
                     power=(1/power);
                }
            if(a==0 && b==0)
                cout<<"not defined";
            else
                {
                      cout<<power;
                }
      
 }