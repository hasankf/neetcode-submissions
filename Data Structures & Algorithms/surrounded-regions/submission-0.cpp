// do dfs from the edges and mark them with some other letter
// then run another loop to make the other O's X and the #'s O
class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n =board.size() , m = board[0].size() ;

        // left and right borders
        for(int row=0 ; row < n; row ++ ){

            if(board[row][0] == 'O') dfs(row, 0, board) ;
            if(board[row][m-1] == 'O') dfs(row, m-1, board) ;

        }

        // top and bottom borders
        for(int col =0; col < m ;col ++ ) {

            if(board[0][col] == 'O') dfs(0, col, board) ;
            if(board[n-1][col] == 'O') dfs(n-1, col, board) ;

        }

        for(int row=0 ; row < n; row ++ ){
            for(int col =0 ; col < m ; col ++ ){

                if(board[row][col] == 'O') board[row][col] = 'X'; 
                else if(board[row][col] == '#') {board[row][col] = 'O';}
            }
        }

        
    }
private:

    void dfs(int row, int col, vector<vector<char>>& board) {

        int n =board.size() , m = board[0].size() ;
        board[row][col] = '#' ;

        int d1[4] = {1, 0, -1, 0 } ;
        int d2[4] = {0, 1, 0 ,-1 } ;

        for(int i=0; i<4; i++ ){
            int nrow = d1[i] + row ;
            int ncol = d2[i] + col ;

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m
            && board[nrow][ncol] == 'O') {

                dfs(nrow, ncol, board) ;
            }
        }
        

    }

};
