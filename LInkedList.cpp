#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

// Push at then end
void Push(Node** pointerToHead, int value){
    Node* temp = new Node();
    temp->data = value;
    if(*pointerToHead == NULL){
        temp->next = *pointerToHead;
        *pointerToHead = temp;
        return;
    }
    Node* nodePointer = *pointerToHead;
    while(nodePointer->next != NULL){
        nodePointer = nodePointer->next;
    }
    nodePointer->next = temp; 
}

// Push at the beginning
void Push(Node** pointerToHead, int value){
    Node* temp = new Node();
    temp->data = value;
    temp->next = *pointerToHead; 
    *pointerToHead = temp; 
}

// Push node at a specific index
void Push(Node** pointerToHead, int value, int index){
    Node* temp = new Node();
    temp->data = value;
    if(index == 1){
        temp->next = *pointerToHead;
        *pointerToHead = temp;
        return;
    }
    Node* nodePointer = *pointerToHead; 
    for(int i = 1; i< index - 1; i++ ){
        nodePointer = nodePointer->next; 
    }
    temp->next = nodePointer->next; 
    nodePointer->next = temp;
}

void Print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next; 
    }
}

int main(){
    Node* head = NULL;
    Push(&head, 9, 1);
    Push(&head, 7, 1);
    Push(&head, 8, 2);
    Print(head);
}
