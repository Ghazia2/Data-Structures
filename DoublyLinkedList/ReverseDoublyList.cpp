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

/*
    What is O(logn)? How it is calculated?
    
    Problem statement: 
    Lets say we a n sized array [11,22,33,44,55,66,77,88...n], and we need to find a digit in this using binary search or divide and compare method.
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(low<=high){
        mid = (low + high)/2;
        if(mid < value)
            low = mid + 1;
        else if(mid > value)
            high = mid - 1;
        else
            return mid;
    }
    
    Math explaination:
    Lets assume the above problem take k iterations in the worst case scenario. And what the worst case scenario you may ask? We can say as we're downsizing the array
    by half each iteration, we will be end with 2 digits, that we can compare and get the answer. Now we know for the worst case, we'll have 2 digits left at the end.
    If we look a iteration before our last iteration we'll sure have 4 digits, and 8 digits before that. 
    2->4->8->........n
    2^1->2^2->2^3....n
    |--------k-------|
    2^1->2^2->2^3....2^k
    Hence, 2^k = n
    k(log2(2)) = log2(n)
    k = log2(n);
*/

int main(){

}
