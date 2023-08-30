class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int j=2;
        int i=0;
        int n=nums.size();
        vector<int>ans;
    
        while(j){
            ans.push_back(nums[i]);
            i++;
            if(i==n){
                i=0;
                j--;
            }
                
        }
        return ans;
    }
};