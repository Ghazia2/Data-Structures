#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next; 
    Node* prev;
};

Node* ReverseDoublyList(Node* head){
    Node* nodePointer = head; 
    Node* prevNode = NULL;
    while(nodePointer){
        prevNode = nodePointer->prev;
        nodePointer->prev = nodePointer->next;
        nodePointer->next = prevNode;
        // increament
        nodePointer = nodePointer->prev;
    }

    // if there is only one node
    // Why prevNode->prev? Our prevNode updates at the start of the loop before the increament. 
    // Hence on the last loop iteration. prevNode will be our seconde last node and nodepointer will be NULL.
    // since the second last node's pointer had been interchanged, hence prevNode->prev;
    if(prevNode != NULL)
        head = prevNode->prev;
    return head;
}

int main(){

}