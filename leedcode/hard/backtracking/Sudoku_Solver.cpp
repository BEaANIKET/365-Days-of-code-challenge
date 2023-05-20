class Solution {
public:

    bool issafe(vector<vector<char>>& board,char val,int row,int col){
        for(int i=0;i<board.size();i++){
            if(board[row][i]==val){
                return false;
            }
            if(board[i][col]==val){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3) + i%3]==val){
                return false ;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board[0].size();
       for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='.'){
                    for(int i=1;i<=9;i++){
                        if(issafe(board,i+'0',row,col)){
                            board[row][col]=i +'0';
                           if(solve(board)){
                               return true;
                           }
                           else{
                               board[row][col]='.';
                           }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
         return ;
    }
};