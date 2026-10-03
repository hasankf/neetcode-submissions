#include <cstring> 
class Solution {
public:
    int t[205][10005] ;
    bool canPartition(vector<int>& nums) {
        
        memset(t, -1, sizeof(t)) ;
        int n = nums.size() ;
        int total_sum  = 0;
        for(int i=0 ;i<nums.size(); i++ ){
            total_sum  += nums[i] ;
        }

        if(total_sum %2 != 0) return false ;
        // we have a pick-notpick situation here 

        int sum = total_sum /2 ;   
        return solve(n-1, sum, nums) ;

    }

private:

    bool solve(int ind, int sum, vector<int>& nums) {

        // base 
        if(sum == 0 ) return true ;
        if(ind == 0 ){
            return (nums[ind] == sum) ;
        }
        // base

        if(t[ind][sum] != -1 ) return t[ind][sum] ;

        int pick =false, notpick =false ;

        notpick = solve(ind-1, sum, nums) ;
        if(nums[ind] <= sum ) {
            pick = solve(ind-1, sum-nums[ind], nums) ;
        }

        return t[ind][sum] = pick || notpick ;



    }


};
