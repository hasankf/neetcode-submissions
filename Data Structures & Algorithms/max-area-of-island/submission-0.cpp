// in this question I am thinking that we could use a DFS driver on this and set a maximum area counter and which will basically keep counting the maximum area whenever we find an island here


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0, area =0 ;
        int n = grid.size() , m = grid[0].size();

        for(int row= 0; row<n; row++ ){
            for(int col=0; col<m; col++ ){

                if(grid[row][col] == 1) {
                    area =0 ;
                    dfshelper(row, col, area, grid) ;
                    maxarea = max(maxarea, area);
                }
            }
        }

        return maxarea;
        

    }
private: 
    void dfshelper(int row, int col, int &area, vector<vector<int>>& grid) {
        
        area = area+1 ;
        grid[row][col] = 0; 
        int n = grid.size() , m = grid[0].size();

        int d1[4] = {1, 0, -1, 0 } ;
        int d2[4] = {0, 1, 0, -1 } ;

        for(int i=0; i<4; i++ ){
            int nrow = d1[i] + row ;
            int ncol = d2[i] + col ;

            if(nrow>=0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 1){
                dfshelper(nrow,ncol,area ,grid) ;
            }
        }
        


    }
}; 