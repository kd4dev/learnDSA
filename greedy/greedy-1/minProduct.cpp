#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
int minProduct(vector<int> &arr){
    int cn=0;
    int cp=0;
    int cz=0;
    int lar_ne=INT_MIN;
    int pos_prod=1;
    int ne_prod=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]== 0) cz++;
        if(arr[i]>0) {
            cp++;
            pos_prod *=arr[i];
        }
        if(arr[i]<0) {
            cn++;
            ne_prod *=arr[i];
            lar_ne=max(lar_ne,arr[i]);
        }
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            auto it=min_element(arr.begin(),arr.end());  
            return *it;  
        }
    }
    else{
        if(cn%2==0){//even
            return ne_prod/lar_ne;
        }
        else{//odd
            return ne_prod*pos_prod;
        }
    }
}
int main(){
    vector<int> arr={-2,-3,1,4,-2};
    cout<<minProduct(arr)<<endl;
}