#include <iostream>
using namespace std;
class Node
{                            // Linked List Node
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
int size(Node* head){
    Node* temp=head;
    int n=0;
    while(temp!=NULL){
        n++;
        temp= temp->next;
    }
    return n;
}
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp= temp->next;
    }
}
void reverseDisplay(Node* head){
    if(head==NULL) return;
    reverseDisplay(head->next);
    cout<<head->val<<" "; 
}
void displayrec(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" "; 
    displayrec(head->next);
}
int main()
{
    Node* a= new Node(10);
    Node* b= new Node(20);
    Node* c= new Node(30);      
    Node* d= new Node(40);
    Node* e=new Node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    cout<<"tail:"<<a->next->next->next->next->val<<endl;
    cout<<"linked list:";
    display(a);
    cout<<endl;
    cout<<"size:"<<size(a);
    cout<<endl;
    cout<<"linked list by recursion:";
    displayrec(a);
    cout<<endl;
    reverseDisplay(a);

}