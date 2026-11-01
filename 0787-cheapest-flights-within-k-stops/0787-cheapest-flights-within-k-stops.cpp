class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, 1e8);
        dis[src] = 0;
        
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dis; // Snapshot of previous step
            for (auto& path : flights) {
                int u = path[0];
                int v = path[1];
                int weight = path[2];
                if (temp[u] != 1e8) {
                    dis[v] = min(dis[v], temp[u] + weight);
                }
            }
        }
        
        return dis[dst] >= 1e8 ? -1 : dis[dst];
    }
};
