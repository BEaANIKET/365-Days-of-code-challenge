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

void inorder(Node* root){
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){

    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root){
    if(root==NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
void buildfromleval(Node* &root){
    queue<Node*>q;
    cout<<"Enter data for root :";
    int Data;
    cin>>Data;
    root=new Node(Data);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter left data of "<<temp->data<<":";
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right data of "<<temp->data<<":";
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){
    
     Node* root=NULL;
    //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     root=buildtree(root);
        // buildfromleval(root);
        cout<<endl;
        levaltraversal(root);

    // traversal(root);

    // cout<<"Inorder traversal is ";
    // inorder(root);
    // cout<<endl;
     
    //  cout<<"Preorder traversal is ";
    //  preorder(root);
    //  cout<<endl;

    //  cout<<"Postorder traversal is ";
    //  postorder(root);

    return 0;
} 