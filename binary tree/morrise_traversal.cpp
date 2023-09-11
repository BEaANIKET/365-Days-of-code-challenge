#include <bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }

};

void MorrisTraversal( Node* root)
{
   Node* curr,pre;
   curr=root;
   while(curr){

        if(curr->left==NULL){
            cout<<curr->data;
            curr=curr->right;
        }
        else{
            pre=curr->left;
            while(prev->right){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                pre->right=NULL;
                cout<<curr->data;
                curr=curr->right;
            }
        }

   }
}

 


int main(){
    
    Node* root=new Node(0);
    root->left
   
return 0;
}
