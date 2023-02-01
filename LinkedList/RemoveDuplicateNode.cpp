#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next; 
};

Node* RemoveDuplicateNodeInASortedList(Node* head, ind index){
    Node* refNode = head; 
    Node* nodePointer = head->next;
    while(nodePointer != NULL){
        if(nodePointer->data == refNode->data){
            Node* duplicateNode = nodePointer;
            nodePointer = nodePointer->next;
            refNode->next = nodePointer;
            delte(duplicateNode);
        }
        else{
            refNode = nodePointer;
            nodePointer = nodePointer->next;
        }
    }
    return head; 
}

int main(){

}