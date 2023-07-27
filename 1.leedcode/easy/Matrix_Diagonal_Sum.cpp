class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      int n=mat.size();
      int sum=0;
        int j=mat.size()-1;
        for(int i=0;i<mat.size() && j>=0;i++){
          sum=sum+mat[i][i]+mat[j--][i];
        }
        return mat.size()%2==0 ? sum:sum-mat[n/2][n/2];
    }
};