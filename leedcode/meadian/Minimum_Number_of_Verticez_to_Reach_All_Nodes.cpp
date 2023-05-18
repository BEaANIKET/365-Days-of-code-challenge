class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>vec(n,false);
        vector<int>ans;
        for(auto a : edges){
            int u = a[0];
            int v = a[1];

            vec[v]=true;
        }
        for(int i=0;i<vec.size();i++){
            if(vec[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};