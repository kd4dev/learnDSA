#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
vector<vector<int>>result;
int v;  
void addEdge(int src,int dest,bool biDir = true){
    graph[src].push_back(dest);
    if(biDir)  graph[dest].push_back(src);
}
void dfs(int curr,int end,vector<int> &path){
    if(curr==end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);  //mark visited
    path.push_back(curr);
    for(auto neighbour:graph[curr]){
        if( visited.find(neighbour) == visited.end() ){
            dfs(neighbour,end,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}
void allPath(int src,int dest){
    vector<int>v;
    return dfs(src , dest ,  v);
}
int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e; cin>>e;
    visited.clear();
    while(e--){
        int s; int d;
        cin>>s; cin>>d;
        addEdge(s,d);
    }
    int x; int y;
    cin>>x; cin>>y;
    allPath(x,y);
    for(auto path:result){
        for(auto ele:path){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
