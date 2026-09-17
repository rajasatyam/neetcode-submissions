#include <bits/stdc++.h>
class Solution {
public:
    int dp[101][101];
    int solve(int i , int n , vector<int>& nums){
        if(i > n) return  0;

        if(dp[i][n] != -1) return dp[i][n];
        int take = nums[i] + solve(i + 2 , n , nums);
        int skip = solve(i + 1 , n , nums);
        return dp[i][n] =  max(take , skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        if(n == 1) return nums[0];
        return max(solve(0 , n - 2 , nums) , solve(1 , n - 1 , nums));
    }
};
