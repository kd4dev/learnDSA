#include<iostream>
#include<climits>
#include<queue>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void preOrder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" "; //work 
    preOrder(root->left); //call1
    preOrder(root->right); //call2
}
void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->left); //call1
    cout<<root->val<<" "; //work 
    inOrder(root->right); //call2
}
void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->left); //call1
    postOrder(root->right); //call2
    cout<<root->val<<" "; //work 
}
void nthLevel(Node* root,int curr,int level){
    if(root==NULL) return;  //base case
    if(curr==level){
        cout<<root->val<<" ";  //root   
        return;
    }
    nthLevel(root->left,curr+1,level);   //left
    nthLevel(root->right,curr+1,level);   //right
}
void nthLevelRev(Node* root,int curr,int level){
    if(root==NULL) return;  //base case
    if(curr==level){
        cout<<root->val<<" ";  //root   
        return;
    }
    nthLevelRev(root->right,curr+1,level);   //right
    nthLevelRev(root->left,curr+1,level);   //left
}
void levelOrderQueue(Node* root){
    queue<Node*>q;
    q.push(root);
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}
void levelOrderQueueRev(Node* root){
    queue<Node*>q;
    q.push(root);
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->right!=NULL) q.push(temp->right);
        if(temp->left!=NULL) q.push(temp->left);
    }
    cout<<endl;
}
int level(Node* root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}
void levelOrder(Node* root) {
    int n=level(root);
    for(int i=1;i<=n;i++ ){
        nthLevel(root,1,i);
        cout<<endl;
    }
}
void levelOrderRev(Node* root) {
    int n=level(root);
    for(int i=1;i<=n;i++ ){
        nthLevelRev(root,1,i);
        cout<<endl;
    }
}
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    levelOrderQueue(a);
        
}
