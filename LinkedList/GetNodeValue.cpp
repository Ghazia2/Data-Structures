#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next; 
};

Node* GetNodeValueFromTheEnd(Node* head, ind index){
    // approch: first we move our first node n nodepointer away from the start 
    // and then move both the pointer till end the end maintaining our n node distance between them. 
    Node* nodePointer = head;
    for(int i=0; i<index; i++){
        head = head->next;
    }
    while(head->next != NULL){
        head = head->next;
        nodePointer = nodePointer->next;
    }
    return nodePointer->next;
}

int main(){

}