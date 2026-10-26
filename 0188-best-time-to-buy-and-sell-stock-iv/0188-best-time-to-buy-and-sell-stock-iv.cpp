class Solution {
    int dp[1001][101][2];

    int fun(int i, int n, int k, int flag, vector<int>& prices) {
        if (i == n || k == 0) {
            return 0;
        }
        if (dp[i][k][flag] != -1) {
            return dp[i][k][flag];
        }

        int profit = 0;

        if (flag == 1) { 
            int buy = -prices[i] + fun(i + 1, n, k, 0, prices);
            int skip = fun(i + 1, n, k, 1, prices);
            profit = max(buy, skip);
        } 
        else { 
            int sell = prices[i] + fun(i + 1, n, k - 1, 1, prices);
            int skip = fun(i + 1, n, k, 0, prices);
            profit = max(sell, skip);
        }

        return dp[i][k][flag] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); 
        if (n == 0 || k == 0) return 0;
        memset(dp, -1, sizeof(dp));
        return fun(0, n, k, 1, prices);
    }
};
