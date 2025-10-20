#include <iostream>
#include <set>
#include <map>
using namespace std;
int main()
{
    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(2321);
    s.insert(234);
    s.insert(6);
    s.insert(4);
    for (int ele : s)
    {
        cout << ele << " ";
    }
    cout<<endl;
    map<int,int>m;
    m[2]=20;
    m[1]=30;
    m[3]=10;
    for ( auto x : m)
    {
        cout << x.first << " ";
    }    
    cout<<endl;
    for ( auto x : m)
    {
        cout << x.second << " ";
    }    
    cout<<endl;
    map<string,int>m1;
    m1["pawade"]=20;
    m1["kedar"]=30;
    m1["ritya"]=10; 
    for ( auto x : m1)
    {
        cout << x.first << " ";
    }    
    cout<<endl;
    for ( auto x : m1)
    {
        cout << x.second << " ";
    }    
}