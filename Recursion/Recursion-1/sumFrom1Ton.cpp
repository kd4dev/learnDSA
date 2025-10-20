#include<iostream>
using namespace std;
void sum1ton(int sum,int n){
    if(n==0) {
        cout<<sum<<endl;
        return;  
    }
    sum1ton(sum+n,n-1);
}
int main(){
    sum1ton(0,10); 
}