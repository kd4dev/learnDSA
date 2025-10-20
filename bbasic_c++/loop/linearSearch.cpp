#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array:";
    cin>>n;


    int arr[n];
        for(int i=0;i<=(n-1);i++){
            cin>>arr[i];
        }
    int x;
    cout<<"enter a element to check:";
    cin>>x;
        bool flag = false; //false=not present
        for(int i=0;i<=(n-1);i++){
            if(arr[i]==x) flag = true;
        }
        if(flag==true) cout<<"element found";
        else cout<<"element not found";

}