class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
         
        for(int i=n-1;i>=0;i--){
           int j=grid[i].size()-1;
            while(j>=0 && grid[i][j]<0 ){
                count++;
                j--;
            }

        }
        return count;
    }
};