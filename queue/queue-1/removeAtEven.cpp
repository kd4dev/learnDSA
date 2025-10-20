#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void removeAtEven(queue<int>& q){
    int n=q.size();
    for(int i=0;i<n;i++){
        if(i%2!=0){
            int x =q.front();
            q.push(x);
        } 
        q.pop();           
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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    removeAtEven(q);
    display(q);
}