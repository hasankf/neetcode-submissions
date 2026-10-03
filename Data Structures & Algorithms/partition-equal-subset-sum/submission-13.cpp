#include <cstring> 
class Solution {
public:
    bool t[205][100005] ;
    bool canPartition(vector<int>& nums) {
        memset(t, 0, sizeof(t)) ;
        int n = nums.size() ;
        int total_sum  = 0;
        for(int i=0 ;i<nums.size(); i++ ){
            total_sum  += nums[i] ;
        }

        if(total_sum %2 != 0) return false ;
        // we have a pick-notpick situation here 

        int tsum = total_sum /2 ;   
        // return solve(n-1, sum, nums) ;

        // tabulation answer 
        // base case 
        for(int i=0 ;i<n; i++ ) t[i][0] = true ;
        
        for(int ind=1; ind<=n; ind++ ){
            for(int sum =1; sum<= tsum; sum++ ) {

                int pick =false, notpick =false ;

                notpick = t[ind-1][sum] ;
                if(nums[ind-1] <= sum ) {
                    pick = t[ind-1][sum-nums[ind-1]] ;
                }

                t[ind][sum] = pick || notpick ;


            }
        }

        return t[n][tsum] ;
    }

private:

    // bool solve(int ind, int sum, vector<int>& nums) {

    //     // base 
    //     if(sum == 0 ) return true ;
    //     if(ind == 0 ){
    //         return (nums[ind] == sum) ;
    //     }
    //     // base

    //     if(t[ind][sum] != -1 ) return t[ind][sum] ;

    //     int pick =false, notpick =false ;

    //     notpick = solve(ind-1, sum, nums) ;
    //     if(nums[ind] <= sum ) {
    //         pick = solve(ind-1, sum-nums[ind], nums) ;
    //     }

    //     return t[ind][sum] = pick || notpick ;



    // }


};
