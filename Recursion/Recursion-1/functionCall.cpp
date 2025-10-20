#include<iostream>
using namespace std;
int product(int m,int n){
    return m*n;
}
int sum(int m,int n){ 
    return m+n;
}
int main(){
    int x=sum(3,4);
    cout<<x<<endl;
    cout<<product(3,4); 
}