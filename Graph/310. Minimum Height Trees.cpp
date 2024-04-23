class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        vector<int> result;
        vector<int> indegree(n);
        map<int, vector<int>> adj;
        
        for(vector<int> vec:edges) {
            int u = vec[0];
            int v = vec[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> que;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 1) 
                que.push(i);
        }
        
        while(n > 2) {
            int size = que.size();
            n -= size; 
            
            while(size--) {
                int u = que.front();
                que.pop();
                for(int v:adj[u]) {
                    indegree[v]--;
                    if(indegree[v] == 1)
                        que.push(v);
                }
            }
        }
        
        while(!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
};



// brut force 

class Solution {
public:

    int BFS (unordered_map<int, vector<int>> &mp, int val){

        queue<int> q;
        q.push(val);
        unordered_map<int, bool> vis;
        vis[val] = true;
        int lvl = 0;

        while(!q.empty()){

            int n = q.size();
            while(n--){
                int temp = q.front();
                q.pop();

                for(auto & a : mp[temp]){

                    if(!vis[a]){
                        q.push(a);
                        vis[a] = true;
                    }
                }
            }

            lvl++;
        }

        return lvl;
        
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
         

        if(n == 1){
            return {0};
        }

        unordered_map<int, vector<int>> mp;
        int flag = 0;

        for(int i=0; i<e.size(); i++){
            mp[e[i][0]].push_back(e[i][1]);
            mp[e[i][1]].push_back(e[i][0]);
            if(mp[e[i][0]].size() > 1 || mp[e[i][1]].size() > 1){
                flag = 1;
            }
        } 

        int mini = INT_MAX;
        vector<int>ans;
        map<int, bool>mp2;

        if(flag == 1){
           for(int i=0; i<n; i++){
                if(mp[i].size() <= 1){
                    mp2[i] = true;
                }
            } 
        }
        

        for(int i=0; i<n; i++){
            if(!mp2[i]){
                int height = BFS(mp, i);
                if(height == mini){
                    ans.push_back(i);
                }
                else if(height < mini){
                    ans = {};
                    ans.push_back(i);
                    mini = height;
                } 
            } 
        }

        return ans;
    }
};