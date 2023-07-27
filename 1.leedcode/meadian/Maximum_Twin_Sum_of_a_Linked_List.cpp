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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>v;
        int ans=0;

        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int n=v.size();
        for(int i=0;i<n/2;i++){
            int sum=v[i]+v[n-1-i];
            ans=max(sum,ans);
        }
        return ans;
    }
};