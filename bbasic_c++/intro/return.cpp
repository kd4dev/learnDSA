#include<iostream>
using namespace std;
int max_three(int a,int b,int c){
   if(a>b && a>c){
    return a;
   }
   else if(b>c && b>a){
        return b;}
   
   else {
        return c;}
    //return max;
}


int main(){
    int a =2,b=9,c=7;
    cout<<max_three(a,b,c);
}