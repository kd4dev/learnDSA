#include <iostream>
#include <stack>
using namespace std;
string removeDupli(string s){
    stack<char> st;
    st.push(s[0]);
    for(int i=1;i<s.length ();i++){
       if(st.top()!=s[i]){
           st.push(s[i]);
       }
    }
    s="";
    while(st.size()>0){
        s +=st.top();
        st.pop();
    }
    return s;
}
int main(){
    string s="aaabbcddaabffg";
    cout<<s<<endl;
    s=removeDupli(s);
    cout<<s<<endl;
}