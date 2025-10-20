#include<iostream>
using namespace std;
int fibbo(int n){
    if(n==1 ||n==2){
        return 1;
    }
    int left=fibbo(n-1);
    int right=fibbo(n-2);
    return left+right;
    //return fibbo(n-1)+fibbo(n-2);
}

int main(){
    for(int i=1;i<=15;i++){
        cout<<fibbo(i)<<" ";
    }
}
