class Solution {
public:

    bool solve(vector<bool>&vis, int s, int d, unordered_map<int, vector<int>> &mp){

        if(s==d){
            return true;
        }
        
        if(vis[s]==true){
            return false;
        }

        vis[s] = true;

        for(auto &val : mp[s]){
            if(solve(vis, val, d, mp)){
                return true;
            }
        }

        return false;

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        unordered_map<int, vector<int>> mp;

        if(source == destination){
            return true;
        }

        for(auto a : edges){
            mp[a[0]].push_back(a[1]);
            mp[a[1]].push_back(a[0]);
        }

        vector<bool>vis(n, false);

        return solve(vis, source, destination, mp);
    }
};