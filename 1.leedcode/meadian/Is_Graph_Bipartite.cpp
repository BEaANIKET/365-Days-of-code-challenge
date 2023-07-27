class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v(n, 0);
       
        for(int i = 0; i < n; i++) {
            if(v[i] == 0) {
                v[i] = 1;
                if(!dfs(graph, v, i))
                    return false;
            }
        }
          
        return true;
    }
  
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& v, int curr) {
        for(int neighbor : graph[curr]) {
            if(v[neighbor] == v[curr])
                return false;

            if(v[neighbor] == 0) {
                v[neighbor] = 3 - v[curr];
                if(!dfs(graph, v, neighbor))
                    return false;
            }
        }
          
        return true;
    }
};
