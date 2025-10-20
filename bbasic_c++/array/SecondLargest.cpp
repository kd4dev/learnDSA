 #include<iostream>
 #include<climits>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array:";
    cin>>n;

    int arr[n];
        for(int i=0;i<=(n-1);i++){
            cin>>arr[i];
        }`
 
    int max = INT_MIN; 
   
        for(int i=0;i<=(n-1);i++){
            if(arr[i]>max) max=arr[i];
        }

    int smax = INT_MIN;
    for(int i=0;i<=(n-1);i++){
            if(arr[i]!=max && smax<arr[i]) smax=arr[i];
        }
 
cout<<max<<endl;
cout<<smax<<endl;

}