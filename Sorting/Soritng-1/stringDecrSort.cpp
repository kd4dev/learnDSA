#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s="AZYZXBDXJK";
    string str;
    for(int i=0;i<s.length();i++){
        if('X'<=s[i]){
            str.push_back(s[i]);
        }
    }
    cout<<str;
    cout<<endl;
    for(int i=0;i<str.length();i++){
        bool flag=true;
        for(int j=0;j<(str.length()-1-i);j++){
            if(str[j]>str[j+1]){
                swap(str[j],str[j+1]);
                flag =false;
            }
        }
        if(flag==true){  //swap didnt happen
            break;
        }
    }
    cout<<endl;
    reverse(str.begin(),str.end());
    for(int i=0;i<str.length();i++){
        cout<<str[i]<<" ";
    }
}
