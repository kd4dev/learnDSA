#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<utility>
#include<climits>
#include<unordered_set>
#define ll long long int
#define pp pair<int,int>
using namespace std;

vector<list<pp>>gr;

void addEdge(int u,int v,int wt,bool biDir=true){
    gr[u].push_back({v,wt});
    if(biDir) gr[v].push_back({u,wt});
}

unordered_map<int,int> djikstra(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp>>pq;  //min Heap --> {wt,node}
    unordered_set<int>vis;
    unordered_map<int,int>mp;
    vector<int>via(n);
    for(int i=0;i<n;i++){
        mp[i]=INT_MAX;
    }
    pq.push({0,src});
    mp[src]=0;
    while(pq.size()!=0){
        pp curr=pq.top();
        if(vis.count(curr.second)){
            pq.pop(); 
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        for(auto neigh:gr[curr.second]){
            if(!vis.count(neigh.first)&& mp[neigh.first]>mp[curr.second]+neigh.second){
                pq.push({mp[curr.second]+neigh.second,neigh.first});
                via[neigh.first]=curr.second;
                mp[neigh.first]=mp[curr.second]+neigh.second;
            }
        }
    }
    return mp;
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    gr.resize(n,list<pp >()); 
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int>sp=djikstra(src,n);
    int dest;
    cin>>dest;
    cout<<sp[dest]<<endl;
}