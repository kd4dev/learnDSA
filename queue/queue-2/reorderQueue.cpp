#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void display(queue<int>& q){
    int n=q.size();
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }

}
void reorder(queue<int>& q){
    stack<int>st;
    int n=q.size();
    //pop 1st half of q into st
    for(int i=0;i<n/2;i++){
        st.push(q.front());
        q.pop();
    }
    //empty stack into queue
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    //pop 2nd half(now first) of q into st
    for(int i=0;i<n/2;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();       
    }
    //reverse q usin stack
    for(int i=0;i<n;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
}
int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    display(q);
    cout<<endl;
    reorder(q);
    display(q);
}