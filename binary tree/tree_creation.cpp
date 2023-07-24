#include<iostream>
#include<queue>

using namespace std;
    
    class Node{
        public:
        int data;
        Node* right;
        Node* left;

        Node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        } 
    };

Node* buildtree(Node* root){
    cout<<"Enter data : "<<endl;
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter left element :"<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter right element :"<<endl;
    root->right=buildtree(root->right);

    return root;
}

void traversal(Node* root){
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
            cout<<temp->data;
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
    //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     root=buildtree(root);
    traversal(root);
     
    return 0;
} 