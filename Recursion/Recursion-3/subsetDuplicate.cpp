#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

void storesubset(string ans, string original, int idx, vector<string> &v,bool flag)
{
    if (idx == original.length())
    {
        v.push_back(ans);
        return;
    }
    char ch = original[idx];
    if(original.length()==1){
        if(flag==true) storesubset(ans+ch, original, idx + 1, v,true);
        storesubset(ans, original, idx + 1, v,true);
        return;
    }
    char dh=original[idx+1];
    if(ch==dh){
        if(flag==true) storesubset(ans+ch, original, idx + 1, v,true);
        storesubset(ans, original, idx + 1, v,false);
    }
    else{
        if(flag==true) storesubset(ans+ch, original, idx + 1, v,true);
        storesubset(ans, original, idx + 1, v,true);
    }
    }

int main()
{
    string str = "aaab";
    vector<string> v;
    storesubset("", str, 0, v,true);
    for (int i=0;i<=v.size();i++)
    {
        cout << v[i] <<" ";
    }
}