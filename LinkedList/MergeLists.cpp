#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next; 
};

// Iterative Method
Node* MergeList(Node* head1, Node* head2){
    // here we are creating a dummy node. We could use a node Pointer instead 
    // but then we have to specify where our head pointer is pointing at the start. 
    Node* headPointer = new Node();
    Node* temp  = headPointer;

    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            temp->next  = head1;
            head1 = head1->next;
        }
        else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if(head1)
        temp->next = head1;
    else if(head2)
        temp->next = head2;
    return headPointer->next;
}

// Recursive Method
Node* MergeListsRecursive(Node* head1, Node* head2{
    Node* head = NULL;

    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    
    if(head1->data <= head2->data){
        head = head1;
        head->next = MergeList(head1->next, head2);
        // head->next will be equal to which data is smaller in next round
        // and then its ->next->next value will be equal to the next duel winner. 
    }
    else{
        head = head2;
        head->next  = MergeList(head1, head2->next);
    }
    // this will return the original head
    return head; 
}

int main(){

}