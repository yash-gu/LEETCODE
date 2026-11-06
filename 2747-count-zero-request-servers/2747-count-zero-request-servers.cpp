class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // Pair up each query with its original index: {query_time, original_index}
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        // Sort queries by their time values
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // Sort logs by their timestamps: log[1] is the time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Map to keep track of server log counts in the current window
        unordered_map<int, int> serverCounts;
        
        int l = 0; // Left pointer for logs
        int r = 0; // Right pointer for logs
        int numLogs = logs.size();
        
        // Process each query
        for (int i = 0; i < m; ++i) {
            int qTime = sortedQueries[i].first;
            int qIndex = sortedQueries[i].second;
            
            // Expand the window: include all logs up to qTime
            while (r < numLogs && logs[r][1] <= qTime) {
                serverCounts[logs[r][0]]++;
                r++;
            }
            
            // Shrink the window: remove all logs strictly before (qTime - x)
            while (l < numLogs && logs[l][1] < qTime - x) {
                int serverId = logs[l][0];
                serverCounts[serverId]--;
                if (serverCounts[serverId] == 0) {
                    serverCounts.erase(serverId);
                }
                l++;
            }
            
            // Servers that DID NOT receive a log = Total servers - Active servers
            ans[qIndex] = n - serverCounts.size();
        }
        
        return ans;
    }
};
