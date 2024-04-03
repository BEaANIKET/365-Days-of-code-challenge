class Solution {
public:

    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool solve(vector<vector<char>>& b, string w,int n , int m , int i, int j, int idx){

        if(idx == w.length()){
            return true;
        }

        if(i<0 || j<0 || i>=n || j>=m || b[i][j]=='.'){
            return false;
        }

        if(b[i][j] != w[idx]){
            return false;
        }

        int temp = b[i][j];
        b[i][j] = '.';

        for(auto &dir : directions){
            int new_i = i+dir[0];
            int new_j = j+dir[1];

            if(solve(b,w,n,m,new_i,new_j,idx+1)){
                return true;
            }
        }

        b[i][j] = temp;

        return false;

    }

    bool exist(vector<vector<char>>& b, string w) {

        int n = b.size();
        int m = b[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(b[i][j] == w[0] && solve(b,w,n,m,i,j,0)){
                    return true;
                }
            }
        }

        return false;
    }
};