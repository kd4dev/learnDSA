#include<iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    pair<string, int> p1;
    pair<string, int> p2;
    pair<string, int> p3;
    p1.first = "kedar";
    p1.second = 76;
    p2.first = "soham";
    p2.second = 15;
    p3.first = "lokesh";
    p3.second = 86;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m["aayush"]=17;
    m.erase("kedar");
    for (pair<string,int> p : m)
    {
        cout << p.first << "-" << p.second << endl;
    }
    cout<<endl;
    cout<<m["lokesh"]<<endl;
    for (auto p : m)
    {
        cout << p.first << "-" << p.second << endl;
    }
}