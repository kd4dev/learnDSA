#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
class Queue{
public:
    int f;
    int b;
    int s;
    
    vector<int>arr;
    Queue(int val){
        f=0;
        b=0;
        s=0;
        vector<int>v(val);
        arr=v;
    }    
    void push(int val){
        if(b==arr.size()){
            cout<<"queue is full"<<endl;
            return;
        }
        arr[b]=val;
        b++;
        s++;
    }
    void pop(){
        if(s==0){
            cout<<"queue is empty"<<endl;
            return;
        }   
        f++;
        s--;
    }
    int front(){
        if(s==0){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(s==0){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[b-1];    
    }
    int size(   ){
        return s;
    }
    bool empty(){
        if(s==0) return true;
        return false;   
    }
    void display(){
        for(int i=f;i<b;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q(5); 
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.push(60);
    q.display();
    q.pop();
    q.display();

}