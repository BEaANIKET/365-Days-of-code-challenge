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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode* >q;
        if(root==NULL){
            return {};
        }
        q.push(root);
        q.push(NULL);
        vector<int>ans;
        TreeNode* temp=root;
        int maxi=INT_MIN;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            
            if(front != NULL)
                maxi=max(maxi,front->val);

            if(front==NULL){
                ans.push_back(maxi);
                maxi=INT_MIN;
                if(!q.empty())
                    q.push(NULL);
            }


            if(front && front->left){
                q.push(front->left);
            }
            if(front && front->right){
                q.push(front->right);
            }

        }
        return ans;
    }
};