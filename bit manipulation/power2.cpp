#include<iostream>
using namespace std;
int maxPower_2(int n){
    n=n|(n>>1);
    n=n|(n>>2);
    n=n|(n>>4);
    n=n|(n>>8);
    n=n|(n>>16);
    return (n+1)>>1;
}

int maxPower2(int x){
    int temp;
    while(x!=0){
        temp=x;
        x=(x&(x-1));
    }
    return temp;
}

int main(){
    cout<<maxPower2(130)<<endl;
    cout<<maxPower_2(130);
}