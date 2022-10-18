#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data){
            this->data = data;
            this->prev = NULL;
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
        head->prev = newnode;
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
        newnode->prev = tail;
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
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void deleteAtHead(Node *&head){
    Node *temp = head;

    head = head -> next;
    head->prev = NULL;
    temp->next = NULL;
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
        curr->prev = NULL;
        delete curr;

        return ;
    }

    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void printAtHead(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
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
    printAtHead(head);

    insertAtHead(head,tail,10);
    printAtHead(head);

    insertAtHead(head,tail,111);
    printAtHead(head);

    insertAtTail(head,tail,6);
    printAtHead(head);

    insertAtTail(head,tail,60);
    printAtHead(head);

    insertAtPosition(head,tail,121,2);
    printAtHead(head);

    //delete at head
    deleteAtHead(head);
    printAtHead(head);

    //delete at end or postion

    // if position is 1
    deleteAtTailOrPostion(head,tail,1);
    printAtHead(head);

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    //if position is last
    deleteAtTailOrPostion(head,tail,4);
    printAtHead(head);

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    //if position is last
    deleteAtTailOrPostion(head,tail,2);
    printAtHead(head);

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
}