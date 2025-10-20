#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

void permutations(vector<string> & v,string ans,string original){
    if(original==""){
       v.push_back(ans);
        return;
    }
    for(int i=0;i<original.length();i++){
        char ch=original[i];
        string left=original.substr(0,i);
        string right=original.substr(i+1);
        permutations(v,ans+ch,left+right);
    }
}
int main()
{
    string  str="1234567899";
    vector<string>v; 
    permutations(v,"",str);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}    