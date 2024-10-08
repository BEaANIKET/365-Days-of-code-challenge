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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, bool> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = true;
        }

        ListNode* curr = head;
        ListNode* prev = new ListNode(-1);
        ListNode* ans = NULL;

        while(curr){
            if(mp[curr -> val]){
                curr = curr-> next;
                if(curr == NULL){
                    prev -> next = curr;
                }
            }else{
                prev -> next = curr;
                prev = curr;
                if(ans == NULL){
                    ans = prev;
                }

                curr = curr -> next;
            }
        }

        return ans ;

    }
};