#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector<int>v(5,2);
    // cout<<v[0]<<" ";
    // cout<<v[1]<<" ";
    vector<vector<int>> v(3, vector<int>(4, 20));
    cout << v.size() << " ";
    cout << v[2][2];
}