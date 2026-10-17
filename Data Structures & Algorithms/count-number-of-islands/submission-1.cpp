class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size() ,m = grid[0].size() ;
        int cnt = 0;

        for(int row =0; row<n; row ++ ){
            for(int col =0; col<m; col ++ ){

                if(grid[row][col] == '1'){
                    cnt ++ ;
                    dfshelper(row, col, grid) ;
                }
            }
        }
        return cnt ;


    }
private:
    void dfshelper(int row, int col, vector<vector<char>>& grid){

        grid[row][col] = '0';
        int n = grid.size() ,m = grid[0].size() ;
        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1') {

                dfshelper(nrow, ncol, grid);
            }

        }
    }
};
