/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
//  algo 
// 1->Node fing (key);
// 2->fing max from key letf this is predecessor
// ans find min from key right this is Successor

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.

    int prev=-1;
    int succ=-1;

   TreeNode * temp=root;

    while(temp && temp->data != key){

        if(temp->data > key){
            succ=temp->data;
            temp=temp->left;
        }

        else{
            prev=temp->data;
            temp=temp->right;
        }
    }

    if(temp==NULL){
        return {prev , succ};
    }
    // prev;
    TreeNode * leftTree=temp->left;
    while(leftTree){
        prev=leftTree->data;
        leftTree=leftTree->right;
    }

    // succ
    TreeNode* rightTree=temp->right;
     while(rightTree){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }

   
   return {prev,succ};
   
    
}