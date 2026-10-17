class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m = grid[0].size() ;

        vector<vector<int>> visited(n, vector<int> (m, 0)) ;
        queue <pair<pair<int,int>, int>> q ; 

        for(int row =0; row < n; row++ ){
            for(int col = 0; col<m; col ++ ){

                if(grid[row][col] == 2 ) {

                    q.push({{row,col}, 0}) ;
                    visited[row][col] = 2;
                }
            }
        }

        int d1[4] = {1, 0, -1, 0 } ;
        int d2[4] = {0, 1, 0, -1 } ;

        int tm =0 ;
        while(!q.empty () ) {

            auto it = q.front(); 
            int row = it.first.first;
            int col = it.first.second;
            int time = it.second ;
            q.pop();

            tm = max(tm, time) ;

            for(int i=0 ; i<4; i++ ){

                int nrow = d1[i] + row ;
                int ncol = d2[i] + col ;

                if(nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m && 
                grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2 ) {

    
                    visited[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, time + 1}) ;
                }
            }
        }

        for(int i =0 ;i<n; i++ ) {
            for(int j =0 ; j<m ; j++ ){

                if(grid[i][j] == 1 && visited[i][j] != 2  ) return -1;
            }
        }

        return tm ;
    }
};
