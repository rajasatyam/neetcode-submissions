class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> mpp;
        int mx = 0 , ans = -1;
        for(int i : nums){
            mpp[i]++;
            if(mpp[i] > mx){
                ans = i;
            }
            mx = max(mx , mpp[i]);
        }
        return ans;
    }
};