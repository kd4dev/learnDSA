#include<iostream>
using namespace std;
int main(){
    string k="kedar";
    int count=0;
    int i=0;
    while(k[i] !='\0'){
        if(k[i]=='a' || k[i]=='e' || k[i]=='i' || k[i]=='0' || k[i]=='u' ){
            count++;
        }
        i++;
    }
    cout<<count;
}