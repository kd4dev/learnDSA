#include <iostream>
using namespace std;

class Node
{ // user defined data type
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList
{ // user defined data structure
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    int getAtIdx(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "invalid index" << endl;
            return -1;
        }
        else if (idx == 0)
            return head->val;
        else if (idx == size - 1)
            return tail->val;
        Node *temp = head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
    void insertAtHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
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
            insertAtEnd(val);
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
        size--;
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
    void deleteAtTail()
    {
        Node *temp = head;
        if (size == 0)
        {
            cout << "list is empty";
            return;
        }
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
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
            size--;
        }
    }
};

int main()
{
    LinkedList ll;      // { }
    ll.insertAtEnd(10); // {10->NULL}
    ll.Display();
    ll.insertAtEnd(20); // {10->20->NULL}
    ll.Display();
    ll.insertAtEnd(30); // {10->20->30->NULL}
    ll.insertAtEnd(40); // {10->20->30->40->NULL}
    ll.Display();
    ll.insertAtHead(50); // {50->10->20->30->40->NULL}
    ll.Display();
    ll.insertAtHead(24); // {24->50->10->20->30->40->NULL}
    ll.Display();
    ll.insertAtIdx(4, 80); // {24->50->10->20->80->30->40->NULL}
    ll.Display();
    cout << ll.getAtIdx(3) << endl;

    ll.deleteAtHead(); // {50->10->20->80->30->40->NULL}
    ll.Display();
    ll.deleteAtTail(); // {50->10->20->80->30->NULL}
    ll.Display();
    ll.deleteAtIdx(3); // {50->10->20->30->NULL}
    ll.Display();
}