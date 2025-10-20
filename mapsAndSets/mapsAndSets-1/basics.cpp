#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
int main(){
    stack<int>st;
    vector<int>v;
    queue<int>q;
    unordered_set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.erase(2);
    int tar=4;
    if(s.find(tar)!=s.end()){ //exists
        cout<<"exists"<<endl;
    }
    else{ // s.find(tar)==s.end() does not exists
        cout<<"does not exist";
    }
    cout<<s.size()<<endl;
    //for eac loop
    for(int ele: s){
        cout<<ele<<" ";
    }
}