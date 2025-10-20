#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<climits>
#include<queue>
using namespace std;

vector<list<int>>graph;
unordered_set<int>visited;
vector<vector<int>>result;

int v;  

void addEdge(int src,int dest,bool biDir = true){
    graph[src].push_back(dest);
    if(biDir)  graph[dest].push_back(src);
}

void bfs(int src,int dest,vector<int>& dist){
    queue<int>qu;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src]=0;
    visited.insert(src);
    qu.push(src);
    while(qu.size()!=0){
        int curr=qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(auto neighbour:graph[curr]){
            if ( visited.find(neighbour) == visited.end() ){
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour]=dist[curr]+1;
            }
        }
    }
    cout<<endl;
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
    vector<int>dist;
    bfs(x,y,dist);
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }

}
