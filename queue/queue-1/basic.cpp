#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverse(queue<int>&q ){
    stack<int>st;
    int n=q.size();
    while(q.size()>0){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }

}
void display(queue<int>& q){
    int n=q.size();
    for(int i=0;i<n;i++){
        int x=q.front();
        cout<<q.front()<<" ";
        q.push(x);
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // cout<<q.back();
    // cout<<endl;
    // cout<<q.front();
    // cout<<endl;
    // q.pop();
    // cout<<endl;
    // cout<<q.size();
    // cout<<endl;
    // cout<<q.back();
    // cout<<endl;
    // cout<<q.front();
    // cout<<endl;

    reverse(q);
    display(q);
    q.pop();
    reverse(q);
    display(q);
}