// #include<iostream>
// using namespace std;
// int main(){
//     int x=3;
//     int y=4;
//     int* p=  &x;
//     int* q = &y;
//     cout<<(*p + *q);
// }

#include<iostream>
using namespace std;
int main(){
int x,y;
int* p=&x;
int* q=&y;
cin>>*p;
cin>>*q;
cout<<*p+*q;
}