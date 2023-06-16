/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int maxi=INT_MIN;
        int level=0,count=0;
        while(!q.empty()){
            int size=q.size(),sum=0;
            count++;
            for(int i=0;i<size;i++){
                TreeNode *curr=q.front();
                sum+=curr->val;
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
           if(sum>maxi){
               maxi=sum;
               level=count;
           }
           
        }
        return level;
    }
};