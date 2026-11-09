class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        // First pass: count the number of servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }

        // Second pass: count servers that share a row or column with at least one other server
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};
