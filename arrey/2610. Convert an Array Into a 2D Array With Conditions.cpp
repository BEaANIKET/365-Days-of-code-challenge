class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        vector<vector<int>>result;
        result.push_back({});
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) == mp.end()){
                
                result[0].push_back(nums[i]);
            }
            else{
                if(result.size()-1 < mp[nums[i]]){
                    result.push_back({});
                }

                
                result[mp[nums[i]]].push_back(nums[i]);
            }

            mp[nums[i]]++;
        }
        return result;
    }
};