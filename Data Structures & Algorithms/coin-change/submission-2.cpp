#include <cstring>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        static int t[12][10005] ;
        int n = coins.size(); 
        // int ans = solve(n, amount, coins) ;?
        // return (ans >= 1e9) ? -1 : ans;

        // tabulation answer .
        memset(t, 0, sizeof(t)) ;
        // base case 
        for(int sum = 0; sum<= amount ; sum ++ ){
            if(sum % coins[0] == 0 ) t[1][sum] = sum / coins[0] ;
            else t[1][sum] = 1e9 ;
        }

        // nested for loops
        for(int ind=2; ind <= n; ind ++ ){
            for(int sum =0 ; sum<=amount; sum ++ ){
                    int pick = 1e9; ;

                    if(coins[ind-1] <= sum) {
                            // either you keep taking || OR || you take and move on
                        pick = 1 + t[ind][sum -coins[ind-1]];
                    }

                    int notpick = t[ind-1][sum] ;

                    t[ind][sum] = min(pick , notpick) ;


            }
        }
        int ans = t[n][amount];
        return (ans >= 1e9) ? -1 : ans;

        
    }
// private:

//     int solve(int ind, int sum, vector<int>& coins) {

//         // base case
//         if(ind ==1 ) {
//             if( sum % coins[0] == 0) return sum/coins[0] ;
//             else return 1e9 ;
//         }
//         // base case

//         int notpick =0, pick = 1e9; ;

//         if(coins[ind-1] <= sum) {
//                 // either you keep taking || OR || you take and move on
//             pick = 1 + solve(ind, sum -coins[ind-1], coins) ;
//         }

//         notpick = solve(ind-1, sum, coins) ;

//         return min(pick , notpick) ;



//     }

};
