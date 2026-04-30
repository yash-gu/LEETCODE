class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, int j) {
        isConnected[i][j] = 0;

        if (i - 1 >= 0 && isConnected[i - 1][j] == 1) {
            dfs(isConnected, i - 1, j);
        } else if (i + 1 < isConnected.size() && isConnected[i + 1][j] == 1) {
            dfs(isConnected, i + 1, j);
        } else if (j - 1 >= 0 && isConnected[i][j - 1] == 1) {
            dfs(isConnected, i, j - 1);
        } else if (j + 1 < isConnected[0].size() && isConnected[i][j + 1] == 1) {
            dfs(isConnected, i, j + 1);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int province = 0;
        int n = isConnected.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    province++;
                    dfs(isConnected, i, j);
                }
            }
        }

        return province;
    }
};