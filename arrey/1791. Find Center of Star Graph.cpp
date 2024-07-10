class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int>mp;

        for(int i=0; i<edges.size();i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }

        int maxi = INT_MIN;
        int ans = 0;
        for( auto a : mp){
            if(a.second == mp.size() - 1){
                return a.first;
            }
        }

        return ans;
    }
};