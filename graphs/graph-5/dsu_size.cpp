#include<iostream>
#include<vector>
using namespace std;

int find(vector<int>& parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void unionBySize(vector<int>& parent, vector<int>& size, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    
    if(a == b) return;  
    

    if(size[a] >= size[b]) {
        parent[b] = a;
        size[a] += size[b];
    } else {
        parent[a] = b;
        size[b] += size[a];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> parent(n+1);
    vector<int> size(n+1, 1);  // Initialize size of each set as 1

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    
    while(m--) {
        string str;
        cin >> str;
        if(str == "union") {
            int x, y;
            cin >> x >> y;
            unionBySize(parent, size, x, y);
        } else {
            int x;
            cin >> x;
            cout << find(parent, x) << endl;
        }
    }
    return 0;
}