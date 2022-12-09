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

void Print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next; 
    }
}

void ReversePrint(Node* nodePointer){
    if(nodePointer == NULL){
        return;
    }
    Print(nodePointer->next);
    cout<<nodePointer->data<<" ";
}

// using Iterative method
void ReverseList(Node** pointerToHead){
    Node* prevNodePointer = NULL;
    Node* curNodePointer = *pointerToHead; 
    Node* nextNodePointer = curNodePointer->next;
    while(curNodePointer != NULL){
        curNodePointer->next = prevNodePointer; 
        prevNodePointer = curNodePointer; 
        curNodePointer = nextNodePointer;
        if(nextNodePointer != NULL)
            nextNodePointer = nextNodePointer->next;
    }
    *pointerToHead = prevNodePointer; 
}

// using recursive method
void ReverseList(Node** pointerToHead, Node* prev, Node* current){
    if(current == NULL){
        Node* firstNode = *pointerToHead; 
        firstNode->next = NULL;
        *pointerToHead = prev;
        return;
    }
    ReverseList(pointerToHead, prev->next, current->next);
    current->next = prev;
}

int main(){
    Node* head = NULL;
    Push(&head, 1);
    Push(&head, 2);
    Push(&head, 3);
    Push(&head, 4);
    Push(&head, 5);
    Print(head);
    cout<<"\nReverse: ";
    ReverseList(&head, head, head->next);
    Print(head);
}
