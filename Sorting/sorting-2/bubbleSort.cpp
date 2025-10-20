#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[6]={1,2,3,4,5,6};
    int n=6;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    // for(int i=0;i<n-1;i++){
    //     //for(int j=0;j<n-1;j++){
    //     for(int j=0;j<n-1-i;j++){
    //         if(arr[j]>arr[j+1]){
    //             // int temp=arr[j];
    //             // arr[j]=arr[j+1];
    //             // arr{j+1}=temp;
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }
    // }

    //bubble sort optimised
    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag =false;
            }
        }
        if(flag==true){  //swap didnt happen
            break;
        }
    }
    cout<<endl;
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}
    