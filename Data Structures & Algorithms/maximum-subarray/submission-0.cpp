class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 , maxSum = nums[0];
        int n = nums.size() , i = 0 ;
        while(i < n){
            if(sum < 0) sum = 0;
            sum += nums[i];
            maxSum = max(maxSum , max(sum , nums[i]));
            i++;
        }

        return maxSum;
    }
};