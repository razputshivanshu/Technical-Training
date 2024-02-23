//what we have learned already

#include<iostream>
using namespace std;


//creating a struct fuction for nodes
struct node{
    int data;
    node *next;
};

// Print the full linked list from the head or the first element of the linkedlist.

void printList(node *n){
    int count=0;
    while(n!=NULL){
        cout<<n->data<<endl;
        n = n->next;
        count++;
    }
    cout<<"Number of elements in the Linked List is: "<<count<<endl;
}

// A function that will insert dynamically in the Linkedlist.
node *push_front(node *head,int newData){
    node *newNode = new node();
    newNode->data=newData;
    newNode->next=head;
    head = newNode;

    return head;


}

int main(){

    node *head = NULL;
    head=push_front(head,5);
    head=push_front(head,7);


    printList(head);

}

