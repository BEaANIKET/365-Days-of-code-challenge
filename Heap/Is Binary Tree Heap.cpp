
// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.



*/
class Solution {
  public:
  
//   return the total no.of node in a tree
    int countNode(struct Node* tree){
        
        if(!tree){
            return 0;
        }
        
        return 1 + countNode(tree->left) + countNode(tree->right);
    }
    
    
    // cheak complete binary tree or not
    bool isCBT(struct Node* tree,int index,int cbt){
        
        if(!tree){
            return true;
        }
        
        if(index>=cbt){
            return false;
        }
        else{
            return isCBT(tree->left,index*2+1,cbt) && isCBT(tree->right,index*2+2,cbt);
        }
    }
    
    // cheak heap or not condition for heap 
    // ->it should be complete bimary tree && should be root ele..is greater then both child
    bool heap(struct Node* root){
        if(!root){
            return true;
        }
        if(!root->right){
            return true;
        }
        
        if(root->data < root->right->data){
            return false;
        }
        else{
            return (root->data > root->left->data && root->data > root->right->data) && heap(root->left) && heap(root->right);
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        
        int cbt = countNode(tree);
        return isCBT(tree,0,cbt) && heap(tree);
        
    }
};
