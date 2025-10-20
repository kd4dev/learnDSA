#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<list>
using namespace std;
vector<list<int>>graph;
int v;  //no. of vertices
void addEdge(int src,int dest,bool biDir = true){
    graph[src].push_back(dest);
    if(biDir)  graph[dest].push_back(src);
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i <<"-->";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<endl;
    }
}
bool bfs(int src){
    unordered_set<int>vis;
    queue<int>q;
    vector<int>par(v,-1);
    q.push(src);
    while(q.size()!=0){
        int curr=q.front();
        q.pop();
        for(auto neigh:graph[curr]){
            if(vis.count(neigh) && par[curr]!=neigh) return true;
            if(!vis.count(neigh)){
                vis.insert(neigh);
                par[neigh]=curr;
                q.push(neigh);
            }
        }
    }
}
bool hasCycle(){
    unordered_set<int>vis ;
    for(int i=0;i<v;i++){
        if(!vis.count(i)){
            bool result=bfs(i);
            if(result==true) return true; 
        }
    }
    return false;
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
    display();
    bool b=hasCycle();
    cout<<b<<endl;
}