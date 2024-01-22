/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5


### Aproach 
->  create a priorties queue of size n
push first kth element in a queue ;

for remaing element campair with the top element  if element is less then the top ele. then 
-> q.pop();
->q.push(less ele..);
respectively 

at the end you have queue which contain kth smallest element of given arrey
you can return q.top();
*/



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > pq;

        for(int i=0;i<nums.size();i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }
            else if (nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};