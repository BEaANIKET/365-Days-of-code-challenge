class Solution {
public:

    vector<int>ans;


    void dfs(int start,int prev,map<int,vector<int>>&mp){

        ans.push_back(start);
        for(int &val : mp[start]){
            if(val!=prev){
                dfs(val,start,mp);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>>mp;

        for(auto vac : adjacentPairs){
            mp[vac[0]].push_back(vac[1]);
            mp[vac[1]].push_back(vac[0]);
        }
        int start=-1;
        for(auto &it : mp){
            if(it.second.size()==1){
                start=it.first;
            }
        }

        dfs(start,INT_MIN,mp);
        return ans;
    }
};
