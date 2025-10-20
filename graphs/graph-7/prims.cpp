#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
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

ll prims(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp>>pq;  //min Heap --> {wt,node}
    unordered_set<int>vis;
    unordered_map<int,int>mp;
    vector<int>par(n+1);
    for(int i=1;i<=n;i++){
        mp[i]=INT_MAX;
    }
    pq.push({0,src});
    mp[src]=-1;
    int totalCount=0; //0-->n-1 edges
    int result=0;//sum of wts
    while(totalCount<n && pq.size()!=0){
        pp curr=pq.top();
        if(vis.count(curr.second)){
            pq.pop(); 
            continue;
        }
        vis.insert(curr.second);
        totalCount++;
        result+=curr.first;
        pq.pop();
        for(auto neigh:gr[curr.second]){
            if(!vis.count(neigh.first)&& mp[neigh.first]>neigh.second){
                pq.push({neigh.second,neigh.first});
                par[neigh.first]=curr.second;
                mp[neigh.first]=neigh.second;
            }
        }
    }
    return result;
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    gr.resize(n+1,list<pp >()); 
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
    int src;
    cin>>src;
    cout<<prims(src,n)<<endl;
}