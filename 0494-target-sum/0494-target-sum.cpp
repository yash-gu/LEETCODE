class Solution {
public:
    int countofSubsetSum(vector<int>& nums, int sum) {
        // sum will always be >= 0 here due to the check in findTargetSumWays
        vector<int> dp(sum + 1, 0);
        dp[0] = 1; 

        for (int x : nums) {
            for (int j = sum; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }
        return dp[sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum_arr = 0; 
        for(int x : nums) sum_arr += x;
        
        // 1. Target cannot be greater than the total possible sum
        // 2. Use abs(target) to handle negative target values safely
        if (abs(target) > sum_arr || (target + sum_arr) % 2 != 0) {
            return 0; 
        }
        
        int sum = (target + sum_arr) / 2;
        \
        if (sum < 0) return 0;
        
        return countofSubsetSum(nums, sum); 
    }
};