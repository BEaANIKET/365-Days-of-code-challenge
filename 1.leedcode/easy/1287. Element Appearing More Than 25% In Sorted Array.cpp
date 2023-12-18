class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count=ceil((double)arr.size()/4);
        map<int,int>mp;
        int prev=INT_MIN;
        int ans=-1;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            if(mp[arr[i]] >= count){
                if(prev <= mp[arr[i]]){
                    ans = arr[i];
                    prev=mp[arr[i]];
                }
               
            }
        }

        return ans;
    }
};