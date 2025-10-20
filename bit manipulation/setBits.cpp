
#include<iostream>
using namespace std;

int countSetBits1(int n){
   return  __builtin_popcount(n);
}
int countSetBits(int n){
    int count=0;
    while(n>0){
        count++;
        n=(n&(n-1));
    }

   return count;
}
int main(){
    cout<<countSetBits(121)<<endl;
    cout<<countSetBits1(121);
}