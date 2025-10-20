#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class DLL
{ // user defined data structure
public:
    Node *head;
    Node *tail;
    int size;
    DLL()
    {
        head = tail = NULL;
        size = 0;
    }
    void insertAtTail(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        head = tail = temp;
        else
        {
            tail->next = temp;
            temp->prev=tail; //extra
            tail = temp;
        }
        size++;
    }
    void insertAtHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head->prev=temp; //extra
            head = temp;
        }
        size++;
    }
    void insertAtIdx(int idx, int val)
    {
        if (idx < 0 || idx > size)
        {
            cout << "invalid" << endl; 
        }
        else if (idx == 0)
        {
            insertAtHead(val);
        }
        else if (idx == size) 
        {
            insertAtTail(val);
        }
        else
        {
            Node *t = new Node(val);
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            t->prev=temp;
            t->next->prev=t;
            size++;
        }
    }
    void deleteAtHead()
    {
        if (size == 0)
        {
            cout << "list is empty";
            return;
        }
        head = head->next;
        if(head) head->prev=NULL; //extra
        if(head==NULL) tail=NULL; //extra
        size--;
    }
    void deleteAtTail()
    {
        if (size == 0)
        {
            cout << "list is empty";
            return;
        }
        else if(size==1){   //extra
            deleteAtHead();
            return;
        }
            Node* temp=tail->prev;  
            temp->next=NULL;
            tail=temp;
            size--;
    }
    void deleteAtIdx(int idx)
    {
        if (size == 0)
        {
            cout << "list is empty";
            return;
        }
        else if (idx < 0 || idx >= size)
        {
            cout << "invalid index";
            return;
        }
        else if (idx == 0)
        {
            return deleteAtHead();
        }
        else if (idx == size - 1)
        {
            return deleteAtTail();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev=temp; //extra
            size--;
        }
    }
    int getAtIdx(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "invalid index" << endl;
            return -1;
        }
        else if (idx == 0)   return head->val;
        else if (idx == size - 1)   return tail->val;
        else{
            if(idx<size/2){
                Node *temp = head;
                for (int i = 0; i <=idx; i++)
                {
                    temp = temp->next;
                }
                return temp->val;
                }
            else{
                Node* temp=tail;
                for (int i = 0; i <size- idx; i++)
                {
                temp = temp->prev;
                }
                return temp->val;
            }
        }
    }
    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    DLL list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.Display();
    list.insertAtTail(40);
    list.Display();
    list.insertAtHead(50);
    list.Display();
    list.insertAtIdx(2,60);
    list.Display();
    list.deleteAtHead(); 
    list.Display();
    list.deleteAtTail(); 
    list.Display();
    list.deleteAtIdx(3 ); 
    list.Display();
    cout<<list.getAtIdx(2);

}