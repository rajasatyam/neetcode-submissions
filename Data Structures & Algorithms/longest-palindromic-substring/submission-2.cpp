class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));

        string t = s;
        reverse(t.begin() , t.end());
        int idx = -1 , mx = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    int origStart = i - dp[i][j];
                    int revStart = n - j;

                    if(origStart == revStart && mx < dp[i][j]){
                        idx = i;
                        mx = dp[i][j];
                    }

                }else{
                    dp[i][j] = 0;
                }
            }
        }

        return s.substr(idx - mx , mx);
    }
};