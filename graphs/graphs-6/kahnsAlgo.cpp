#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

// Global adjacency list representation of graph
// Each index represents a vertex and contains a list of its neighbors
vector<list<int>> graph;
int v;  // Total number of vertices in the graph

// Function to add edge between two vertices
// Parameters:
// a: source vertex
// b: destination vertex
// bidir: if true, adds bidirectional edge (default is false for DAG)
void addEdge(int a, int b, bool bidir = false) {
    graph[a].push_back(b);  // Add edge from a to b
    if(bidir) {
        graph[b].push_back(a);  // If bidirectional, add edge from b to a
    }
}

// Kahn's Algorithm for Topological Sorting using BFS
void topoBFS() {
    // Array to store indegree (incoming edges) for each vertex
    vector<int> indegree(v, 0);
    
    // Calculate indegree for each vertex
    // For each vertex, increment indegree of all its neighbors
    for(int i = 0; i < v; i++) {
        for(auto neigh : graph[i]) {
            indegree[neigh]++;
        }
    }

    // Queue to store vertices with 0 indegree
    queue<int> q;
    
    // Add all vertices with 0 indegree to queue
    // These vertices have no dependencies and can be processed first
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;  // Count of processed vertices
    cout << "Topological Order: ";
    
    // Process vertices in topological order
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";  // Print current vertex
        count++;

        // For each neighbor of current vertex
        // Decrease its indegree by 1
        // If indegree becomes 0, add to queue
        for(auto neigh : graph[node]) {
            indegree[neigh]--;
            if(indegree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }
    cout << endl;

    // If count != total vertices, graph has cycle
    if(count != v) {
        cout << "Graph contains cycle!" << endl;
    }
}

int main() {
    cin >> v;  // Input number of vertices
    graph.resize(v, list<int>());  // Initialize adjacency list
    
    int e;  // Number of edges
    cin >> e;
    
    // Input edges: source and destination for each edge
    while(e--) {
        int x, y;  // x: source vertex, y: destination vertex
        cin >> x >> y;
        addEdge(x, y);  // Add directed edge from x to y
    }
    
    // Perform topological sort
    topoBFS();
}