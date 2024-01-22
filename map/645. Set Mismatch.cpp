class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       map<int,vector<int>>mp;
       for(int i=0;i<nums.size();i++){
           mp[nums[i]].push_back(i+1);
       }

        int ans2 = -1;
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i) == mp.end()){
                ans2 = i;
                break;
            }
        }

       for(auto a : mp){
           if(a.second.size()==2){
               return {a.first,ans2};
           }
       }
       return {};
    }
};