class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>ans;

        for(auto a : mp){
            ans.push_back(a.second);
        }

        sort(ans.begin(),ans.end());

        for(int i=1;i<ans.size();i++){
            if(ans[i] == ans[i-1]){
                return false;
            }
        }

        return true;
    }
};