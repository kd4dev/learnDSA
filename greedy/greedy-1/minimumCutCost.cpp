#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#define ll long long int
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
ll minCostToBreakGrid(int n,int m,vector<ll> &horizontal,vector<ll> &vertical){
    sort(horizontal.begin(),horizontal.end(),cmp);
    sort(vertical.begin(),vertical.end(),cmp);
    int h=0;
    int v=0;
    int ans=0;
    int hz=1,vr=1;
    while(h<horizontal.size() && v<vertical.size()){
         if(vertical[v]>horizontal[h]){
            ans+=vertical[v]*vr;
            hz++;
            v++  ;
        }
        else{
            ans +=horizontal[h]*hz;
            vr++;
            h++;
        }
    }
    while(h<horizontal.size()){
        ans+= horizontal[h]*hz;
        vr++;
        h++;
    }
    while(v<vertical.size()){
        ans +=vertical[v]*vr;
        hz++;
        v++;
    }
    return ans;

}


int main(){
    int     n,m;
    cin>>m>>n;
    vector<ll>horizontal,vertical;
    for(int i=0;i<m-1;i++){
        int x;
        cin>>x;
        vertical.push_back(x);
    }
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        horizontal.push_back(x);
    }
    cout<<minCostToBreakGrid(n,m,horizontal,vertical);
}