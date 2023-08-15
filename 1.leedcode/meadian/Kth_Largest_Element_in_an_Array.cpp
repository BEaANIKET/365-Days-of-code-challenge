class Solution {
public:
    int solve(vector<int>&nums,int k){
         priority_queue<int>pq(nums.begin(),nums.end());
         while(k!=1){
              pq.pop();
              k--;
         }
         return pq.top();

    }
    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums,k);
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q(nums.begin(),nums.end());
        while(k>1){
            q.pop();
            k--;
        }
        return q.top();
    }
};