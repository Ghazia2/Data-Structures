#include<iostream>

using namespace std;

struct Node{
  int data;
  Node* prev;
  Node* next; 
};

void Push(Node** pointerToHead, int value){
    Node* temp = new Node();
    temp->data = value; 
    temp->next = NULL;
    if(*pointerToHead == NULL){
        temp->prev = *pointerToHead;
        *pointerToHead = temp; 
        return;
    }
    Node* nodePointer = *pointerToHead; 
    while(nodePointer->next != NULL){
        nodePointer = nodePointer->next; 
    }
    temp->prev = nodePointer; 
    nodePointer->next = temp;
}

void Print(Node* nodePointer){
    cout<<"\nList: ";
    while(nodePointer != NULL){
        cout<<nodePointer->data<<" ";
        nodePointer = nodePointer->next; 
    }
}

void ReversePrint(Node* nodePointer){
    while(nodePointer->next != NULL){
        nodePointer = nodePointer->next;
    }
    cout<<"\nReverse Print: ";
    while(nodePointer != NULL){
        cout<<nodePointer->data<<" ";
        nodePointer = nodePointer->prev;
    }
}

void Delete(Node** pointerToHead, int index){
    Node* nodePointer = *pointerToHead;
    if(index == 1){
        *pointerToHead = nodePointer->next; 
        delete(nodePointer);
        return;
    }
    for(int i=0; i< index - 1; i++){
        nodePointer = nodePointer->next; 
    }
    nodePointer->prev->next = nodePointer->next;
    nodePointer->next->prev = nodePointer->prev; 
}

int main(){
    Node* head = NULL;
    Push(&head, 1);
    Push(&head, 6);
    Push(&head, 2);
    Push(&head, 3);
    Print(head);
    ReversePrint(head);
    cout<<"\n---Deleted list---";
    Delete(&head, 2);
    Print(head);
    ReversePrint(head);
}