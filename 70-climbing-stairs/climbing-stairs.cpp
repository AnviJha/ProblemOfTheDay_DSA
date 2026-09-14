class Solution {
public:
//memoization 
    int ans( vector<int>&dp , int n){
        if(n<=2) return n;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = ans(dp ,n-1) + ans(dp,n-2 ) ;
        
    }
    
    int climbStairs(int n) {
      //memoization 
        
        vector<int>dp(n+1,-1);
        return ans(dp,n);

    }
};

/*Tabulation

 if(n <= 2)
            return n;

        vector<int> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
*/