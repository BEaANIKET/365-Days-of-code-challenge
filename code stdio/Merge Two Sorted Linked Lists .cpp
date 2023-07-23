#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>*dummy=new Node<int>(0);
    Node<int>*temp=dummy;

    Node<int>*temp1;
    Node<int>*temp2;

    temp1=first;
    temp2=second;

    while(temp1!=NULL && temp2!=NULL){

        if(temp1->data<temp2->data){
            temp->next=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp2=temp2->next;
        }     

        temp=temp->next;   
    }

    while(temp1){
        temp->next=temp1;
        temp=temp->next;
        temp1=temp1->next;
    }

    while(temp2){
        temp->next=temp2;
        temp=temp->next;
        temp2=temp->next;
    }
    temp->next=NULL;

    return dummy->next;
}
