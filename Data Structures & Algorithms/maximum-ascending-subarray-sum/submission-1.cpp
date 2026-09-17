class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size() , i = 1;
        int curr = nums[0] , sum = 0;
        while(i < n){
            sum = max(sum , curr);
            if(nums[i] <= nums[i - 1]){
                curr = nums[i];
            }else{
                curr += nums[i];
            }
            i++;
        }
        return max(curr ,sum);
    }
};