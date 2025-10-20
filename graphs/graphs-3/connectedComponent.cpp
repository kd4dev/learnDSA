#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>>graph;
int v;  //no. of vertices
void addEdge(int src,int dest,bool biDir = true){
    graph[src].push_back(dest);
    if(biDir)  graph[dest].push_back(src);
}

void dfs(int node,unordered_set<int> &visited){
    visited.insert(node);
    for(auto neighbor:graph[node]){
        if(visited.find(neighbor)==visited.end()){
            dfs(neighbor,visited);
        }
    }
}
int connectedComponents(){
    int result=0;
    unordered_set<int>visited;
    for(int i=0;i<v;i++){
        //go to every vertex
        //if we can initialise dfs from any vertex then we got one more connected component
        if(visited.count(i)==0){
            result++;
            dfs(i,visited);
        }
    }
    return result;
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e; cin>>e;
    while(e--){
        int s; int d;
        cin>>s>>d;
        addEdge(s,d,false);
    }
    cout<<connectedComponents()<<endl;
}