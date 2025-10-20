#include<iostream>
#include<algorithm>
using namespace std;
int main(){
//     string s="abcdef";
//     cout<<s.substr(2)<<endl;
//     cout<<s.substr(1,3);

string str;
cout<<"enter a string:";
cin>>str;
int n=str.length();
cout<<str.substr(n/2);
 }
