class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int c1 = 0 , c0 = 0;
        for(char c : s){
            if(c == '1') c1++;
        }
        vector<int> ans(n , 0);
        int mx = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            if(s[i] == '0'){
                c0++;
                ans[i] = c0 + c1;
            }else c1--;
            mx = max(mx , c0 + c1);
        }
        return mx;

    }
};