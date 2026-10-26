class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, long long &sum) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return;
        }
        
        sum += grid[i][j];
        grid[i][j] = 0;
        
        dfs(i + 1, j, grid, sum);
        dfs(i - 1, j, grid, sum);
        dfs(i, j - 1, grid, sum);
        dfs(i, j + 1, grid, sum);
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int total_island = 0;
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    long long sum = 0;
                    dfs(i, j, grid, sum);
                    
                    if (sum % k == 0) {
                        total_island++;
                    }
                }
            }
        }
        return total_island;
    }
};
