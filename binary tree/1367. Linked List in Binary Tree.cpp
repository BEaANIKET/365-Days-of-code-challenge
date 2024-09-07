/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    bool solve( TreeNode* root, ListNode* head ){
        if(!head)return true;
        if(!root) return true;

        if(head -> val != root->val){
            return false;
        }

        return solve(root->left, head -> next) || solve(root->right, head -> next);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head ){
            return false;
        }
        if(!root) return false;

        return solve(root, head) || solve(root -> left, head) || solve(root-> right, head);
    }
};