#include <bits/stdc++.h>
using namespace std;

class Node{

    public:

    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertAtbst(Node* root,int data){

    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data > root->data){
        root->right=insertAtbst(root->right,data);
    }
    else{
        root->left=insertAtbst(root->left,data);
    }
 
    return root;
}

void takeInput(Node* &root){

    int data;
    cin>>data;

    while(data!=-1){
        root=insertAtbst(root,data);
        cin>>data;
    }
}

void levaltraversal(Node* root){
    queue<Node* >q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){
        Node* temp=q.front(); 
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            } 
        }
       
    }
}

int main(){
    
    Node* root=NULL;
    cout<<"Enter data"<<endl;
    takeInput(root);
    levaltraversal(root);

     
    return 0;
}
