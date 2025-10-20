#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
int v;  
void addEdge(int src,int dest,bool biDir = true){
    graph[src].push_back(dest);
    if(biDir)  graph[dest].push_back(src);
}
bool dfs(int curr,int end){
    if(curr==end) return true;
    visited.insert(curr);  //mark visited
    for(auto neighbour:graph[curr]){
        if( visited.find(neighbour) == visited.end() ){
            bool result=dfs(neighbour,end);
            if( result ) return true;
        }
    }
    return false;
}
bool anyPath(int src,int dest){
    return dfs(src,dest);
}
int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e; cin>>e;
    visited.clear();
    while(e--){
        int s; int d;
        cin>>s; cin>>d;
        addEdge(s,d,false);
    }
    int x; int y;
    cin>>x; cin>>y;
    cout<<anyPath(x,y)<<endl;
}
