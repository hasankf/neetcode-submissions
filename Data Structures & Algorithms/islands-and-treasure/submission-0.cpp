#define INF 2147483647
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n= grid.size(), m= grid[0].size() ; 
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<n; i++ ){
            for(int j=0; j<m; j++ ){

                if(grid[i][j] == 0 ) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int d1[4] = {1, 0, -1, 0 } ;
        int d2[4] = {0, 1, 0, -1 } ;

        while(!q.empty() ) {
            int row = q.front().first.first, col = q.front().first.second;
            int dis = q.front().second ;
            q.pop();

            for(int i=0; i<4 ; i++ ){
                int nrow = d1[i] + row ;
                int ncol = d2[i] + col ;

                if(nrow>=0 && nrow < n && ncol>=0 && ncol< m 
                && grid[nrow][ncol] == INF) {
                    
                    grid[nrow][ncol] = dis+1 ;
                    q.push({{nrow,ncol}, dis+1});
                }
            }

        }
        
    }
};
