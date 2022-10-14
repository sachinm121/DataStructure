#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node *next;

     Node(int data){
        this->data = data;
        this->next = NULL;
     }

};

void insertAtHead(Node *&head,Node *&tail,int data){
    Node *newnode = new Node(data);
    if(head == NULL){
        head = tail = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void insertAtTail(Node *&head,Node *&tail,int data){
    Node *newnode = new Node(data);

    if(head == NULL){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}

void insertAtPosition(Node *&head,Node *&tail,int data,int position){

    //if postion is head
    if(position == 1){
        insertAtHead(head,tail,data);
        return;
    }

    //if postion is either end or middle

    Node *temp = head;
    int cnt = 1;

    while(cnt < position-1){
        cnt++;
        temp = temp->next;
    }

    //if temp->next == NULL it means end
    if(temp->next == NULL){
        insertAtTail(head,tail,data);
        return ;
    }

    Node *newnode = new Node(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteAtHead(Node *&head){
    Node *temp = head;
    head = head->next;

    temp = NULL;
    delete temp;
}

void deleteAtTailOrPostion(Node *&head,Node *&tail,int position){

    if(position == 1){
        deleteAtHead(head);
        return;
    }
    Node *prev = NULL;
    Node *curr = head;

    int cnt = 1;
    while(cnt < position){
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    //delete at tail
    if(curr->next == NULL){
        tail = prev;
        tail->next = NULL;
        delete curr;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head){
    Node *temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head,tail,5);
    print(head);
    // cout << "Length : " << getLength(head) << endl << endl;

    insertAtHead(head,tail,9);
    print(head);
    // cout << "Length : " << getLength(head) << endl << endl;

    insertAtHead(head,tail,25);
    print(head);
    // cout << "Length : " << getLength(head) << endl << endl;

    insertAtTail(head,tail,100);
    print(head);
    // cout << "Length : " << getLength(head) << endl << endl;

    insertAtTail(head,tail,101);
    print(head);
    // cout << "Length : " << getLength(head) << endl << endl;

    //insert at head using position function
    insertAtPosition(head,tail,125,1);
    print(head);
    //cout << "Length : " << getLength(head) << endl << endl;

    //insert at head using position function
    insertAtPosition(head,tail,130,7);
    print(head);
    //cout << "Length : " << getLength(head) << endl << endl;

    //insert at middle using position function
    insertAtPosition(head,tail,200,4);
    print(head);
    //cout << "Length : " << getLength(head) << endl << endl;

    //Delete at head
    deleteAtHead(head);
    print(head);

    //Delete at either end or middle
    deleteAtTailOrPostion(head,tail,4);
    print(head);
}