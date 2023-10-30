class Solution {
public:

   int Count(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            int count=Count(arr[i]);
            mp[count].push_back(arr[i]);
        }
        vector<int>ans;
        for(auto a : mp){
            
            sort(a.second.begin(), a.second.end());
            for(int i=0;i<a.second.size();i++){
                ans.push_back(a.second[i]);
            }
        }
        return ans;
    }
};