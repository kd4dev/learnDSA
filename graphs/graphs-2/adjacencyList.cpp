#include<iostream>
#include<vector>
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
}