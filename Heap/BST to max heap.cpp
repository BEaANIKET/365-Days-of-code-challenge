/*struct Node {
    int data;
    Node *left, *right;
};*/

/*
Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

Example 1:

Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output : 1 2 3 4 5 6 7 
Exaplanation :
               7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a
Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.


-->Approch convert this BST inorder to postorder
*/
class Solution{
  public:
    
    void inorder(Node* root,vector<int>&ans){
        if(!root){
            return ;
        }
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        
        return ;
    }
    
    int i = 0;
    void postorder(Node* root,vector<int>&ans){
        if(!root){
            return ;
        }
        
        postorder(root->left,ans);
        postorder(root->right,ans);
        root->data = ans[i++];
        
        return ;
    }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int>ans;
        inorder(root,ans);
        postorder(root,ans);
        
        return ;
    }    
};