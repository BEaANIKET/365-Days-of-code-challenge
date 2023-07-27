class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start=0;
        int end=0;
        int n=nums.size();
        int skip=0;
        int ans=INT_MIN;
        while(end<n){
            if(nums[end]==0){
                skip++;
            }

            while(skip>1){
                if(nums[start]==0){
                    skip--;
                }

                start++;
              
            }

            ans=max(ans,end-start);
            end++;
        }
        return ans;
    }
};

// second method 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start=0;
        int end=0;
        int n=nums.size();
        int last_zero=-1;
        int ans=INT_MIN;
        while(end<n){
                        
            if(nums[end]==0){
                start=last_zero+1;
                last_zero=end;
            }


            ans=max(ans,end-start);
            end++;
        }
        return ans;
    }
};