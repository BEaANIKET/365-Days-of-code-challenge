class Solution {
public:
    void solve(map<int, vector<int>>& mp, int n, vector<vector<int>>& ans, int a, int i,  vector<int> &vis) {
        if (i >= n) {
            return;
        }

        for (int j = 0; j < mp[i].size(); j++) {
            int acetor = mp[i][j];
            if( vis[acetor] ){
                continue;
            }
            ans[acetor].push_back(a);
            vis[acetor] = true;  
            solve(mp, n, ans, a, acetor, vis);
        }

        return;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) {
        vector<vector<int>> ans(n); 
        map<int, vector<int>> mp;

        for (int i = 0; i < e.size(); i++) {
            int from = e[i][0];
            int to = e[i][1];
            mp[from].push_back(to);  
        }

        for (int i = 0; i < n; i++) {
            vector<int> vis(n, false);
            solve(mp, n, ans, i, i, vis);
        }

        return ans;
    }
};
