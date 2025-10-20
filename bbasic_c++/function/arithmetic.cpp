#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"enter a number:";
    cin>>a;
    int* p=&a;
    // cout<<p; 
    // p++;
    // cout<<p;
    *p=*p + 1;
    cout<<*p<<endl;
}