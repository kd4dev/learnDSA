#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){
    int k=2;
    stack<int>st;
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();       
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    int n=q.size();
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
    cout<<endl;

}