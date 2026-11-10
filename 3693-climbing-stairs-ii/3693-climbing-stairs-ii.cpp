class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= 3; k++) {
                if (i + k <= n) {
                    int totalCost = dp[i] + costs[i + k - 1] + (k * k);
                    dp[i + k] = min(dp[i + k], totalCost);
                }
            }
        }

        return dp[n];
    }
};
