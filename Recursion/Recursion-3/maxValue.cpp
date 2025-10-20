 #include<iostream>
 #include<vector>
 #include<climits>
using namespace std;
int max(int arr[ ],int n,int idx){
    return max(arr[idx],max(arr,n,idx ));
}
void printMax(int arr[],int n,int idx,int max){
    if(idx==n) {
        cout<<max;
        return;
    }
    if(arr[idx]>max) max=arr[idx];                  
    printMax(arr,n,idx+1,max);
}


int main(){
    int arr[ ]={2,1,6,3,9,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    printMax(arr,n,0,INT_MIN);
    cout<<endl;
    cout<<max(arr,n,0);
}