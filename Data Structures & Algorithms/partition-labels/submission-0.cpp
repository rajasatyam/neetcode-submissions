class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.size();
        vector<int> count(26 , 0);
        for(char c : s){
            count[c - 'a']++;
        }
        int i = 0 , total = 0 , len = 0; 
        while(i < n){
            vector<int> t(26 , -1);
            t[s[i] - 'a'] = 1;
            count[s[i] - 'a']--;
            total = count[s[i] - 'a'];
            len = 1;
            i++;
            while(total > 0 && i < n){
                if(t[s[i] - 'a'] == -1){
                    count[s[i] - 'a']--;
                    t[s[i] - 'a'] = 1;
                    total += count[s[i] - 'a'];
                }else{
                    total--;
                    count[s[i] - 'a']--;
                }
                i++;
                len++;
            }
            if(total == 0) ans.push_back(len);
            // i++;
        }
        return ans;
    }
};