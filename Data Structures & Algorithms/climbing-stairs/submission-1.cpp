#include <bits/stdc++.h>
class Solution {
public:
    int dp[46];
    int solve(int i , int& n){
        if(i > n) return 0;
        if(i == n) return 1;

        if(dp[i] != -1) return dp[i];

        return dp[i] = solve(i + 1 , n) + solve(i + 2 , n);
    }
    int climbStairs(int n) {
        memset(dp , -1 , sizeof(dp));
        int ans = solve(0 , n);
        return ans;
    }
};
