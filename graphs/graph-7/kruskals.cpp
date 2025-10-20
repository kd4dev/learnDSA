#include <iostream>
#include<algorithm>
#define ll long long int
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
int find(vector<int> &parent, int a){
    return parent[a] =((parent[a] == a) ? a : find(parent, parent[a]));
}
void Union(vector<int>& par,vector<int>&rank,int a,int b){
    a=find(par,a);
    b=find(par,b);
    if(a==b) return;
    if(rank[a]>rank[b]){
        rank[a]++;
        par[b]=a;   
    }
    else{
        rank[b]++;
        par[a]=b; 
    }
}
struct Edge{
    int src;
    int dest;
    int wt;
};
bool cmp(Edge e1, Edge e2){
    return e1.wt<e2.wt;
}
ll kruskals(vector<Edge> &input,int n,int e){
    sort(input.begin(),input.end(),cmp);
    vector<int>parent(n+1);
    vector<int>rank(n+1,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int edgeCount=0; //n-1
    int i=0;
    ll ans=0;
    while(edgeCount<n-1 && i<input.size()){
        Edge curr=input[i]; //because input is sorted
        int srcPar=find(parent,curr.src);
        int destPar=find(parent,curr.dest);
        if(srcPar!=destPar){
            //include as this does not make cycle
            Union(parent,rank,srcPar,destPar);
            ans +=curr.wt;
            edgeCount++;
        }
        i++; //doesnt atter you picked last edge or not we still need to go to next edge
    }
    return ans; 
}
int main(){
    int n;
    int e;
    cin>>n>>e;
    vector<Edge>v(e);
    for(int i=0;i<e;i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskals(v,n,e)<<endl;
}









