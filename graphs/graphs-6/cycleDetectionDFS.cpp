#include<iostream>
#include<vector>
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
bool dfs(int src,int parent,unordered_set<int> &vis){
    vis.insert(src);
    for(auto neigh:graph[src]){
        if(vis.count(neigh) && neigh!=parent){
            //cycle detected    
            return true;
        }
        if(!vis.count(neigh)){
            bool res=dfs(neigh,src,vis);
            if(res==true) return true;
        }
    }
    return false;
}
bool hasCycle(){
    unordered_set<int>vis ;
    bool result=false;
    for(int i=0;i<v;i++){
        if(!vis.count(i)){
            result=dfs(i,-1,vis);
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