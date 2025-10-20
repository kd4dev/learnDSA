#include <iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v; //dont need to mention size here
    v.push_back(6);  // 1 1
    v.push_back(1);  // 2 2
    v.push_back(9);  // 3 4
    v.push_back(10);  //4 8
    v.push_back(6);  //5 8
    v.push_back(1); //6 8
    v.push_back(9); // 7 8
    v.push_back(10); // 8 8
    v.push_back(6); // 9 16
    v.push_back(1); // 10 16
    v.push_back(9); // 11 16
    v.push_back(10); //12 16 
    for(int i=0;i<=v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.pop_back();
    v.pop_back();
    for(int i=0;i<=v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}