#include <iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v; //dont need to mention size here
    v.push_back(6);
    cout<<v.size()<<endl;
    v.push_back(1);
    v.push_back(9);
    cout<<v.capacity()<<endl;
    v.push_back(0);
    cout<<v[0]<<" ";
    cout<<v[1]<<" ";
    cout<<v[2]<<" ";
    cout<<v[3]<<" ";
}