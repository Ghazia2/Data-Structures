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

void Delete(Node** pointerToHead, int index){
    Node* nodePointer = *pointerToHead;
    if(index == 1){
        *pointerToHead = nodePointer->next; 
        delete(nodePointer);
        return;
    }
    
    //why index - 2?? while running a loop from 0 to index, it will run index number of times. But we want it a to point a node earlier to our index node, so, index - 1. Also, notice that we're already at node#1 ( Noed* nodePointer = *pointerToHead) so -> index - 2. 
    for(int i = 0; i< index - 2; i++){
        nodePointer = nodePointer->next; 
    }
    Node* nextNodePointer = nodePointer->next; 
    nodePointer->next = nextNodePointer->next;
    delete(nextNodePointer);
}

int main(){
    Node* head = NULL;
    Push(&head, 9);
    Push(&head, 7);
    Push(&head, 8);
    Print(head);
    cout<<"\nList: ";
    Delete(&head, 1);
    Print(head);
}
