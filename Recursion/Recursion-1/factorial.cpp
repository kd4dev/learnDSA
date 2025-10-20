#include<iostream>
using namespace std;
void factUpto(int n){
     int f=1;
    for(int j=1;j<=n;j++){       
            f *=j;
            cout<<f<<endl;
    }
}
 
int main(){
    factUpto(5);
}