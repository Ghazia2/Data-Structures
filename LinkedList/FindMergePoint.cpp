#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next; 
};

// METHOD 1: By modifying list
Node* FindMergePoint(Node* head1, Node* head2){
    Node* tempNode = new Node();
    Node* nodePointer = head1;
    while(head1){
        nodePointer = nodePointer->next;
        head1->next = tempNode;
        head1 = nodePointer;
    }
    while(head2){
        if(head2->next == tempNode)
            return head2->data;
        else
            head2 = head2->next;
    }
    return -1;
}

// METHOD 2: Without modifying list
Node* FindMergePointAlternative(Node* head1, Node* head2){
    
}

int main(){

}