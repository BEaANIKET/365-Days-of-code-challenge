
// You are given an m x n integer matrix matrix with the following two properties:

//     Each row is sorted in non-decreasing order.
//     The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.
/* 
 Aprroach 

1. make this 2d arrey into a 1D array 
2.place l = 0 , place r = n*m -1, and find mid point and we can find the 2D codinate of this mid point by 
  row of mid = mid / matrix[0].size();
  col = mid % matrix[0].size();

  and follow the bs algo 


*/



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int l = 0;
        int n = mat.size();
        int m = mat[0].size();
        int r = n*m -1;

        while(l<=r){

            int mid = (l+r) / 2;

            int row = mid/m;
            int col = mid%m;

            if(mat[row][col] == target){
                return true;
            }

            else if(mat[row][col] < target){
                l = mid+1;
            }

            else{
                r = mid-1;
            }
        }

        return false;
    }
};