 #include<iostream>
using namespace std;
void print(int i,int n){
    if(i>=n) return;
    cout<<i<<endl;
    print(i+1,n);
}
 
int main(){
    int n;
    cin>>n;
    cout<<"enter a number:";
    print(1,n);
}