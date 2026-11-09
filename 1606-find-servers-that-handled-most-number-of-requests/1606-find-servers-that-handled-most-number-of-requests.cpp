#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free_servers;
        for (int i = 0; i < k; ++i) {
            free_servers.insert(i);
        }

        // Min-heap to store pairs of {end_time, server_id}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy_servers;

        vector<int> request_count(k, 0);

        for (int i = 0; i < arrival.size(); ++i) {
            int start_time = arrival[i];
            int end_time = start_time + load[i];

            // Free up servers whose tasks have finished by start_time
            while (!busy_servers.empty() && busy_servers.top().first <= start_time) {
                free_servers.insert(busy_servers.top().second);
                busy_servers.pop();
            }

            // If no servers are available, drop the request
            if (free_servers.empty()) {
                continue;
            }

            // Find the first available server >= (i % k)
            auto it = free_servers.lower_bound(i % k);
            if (it == free_servers.end()) {
                it = free_servers.begin();
            }

            int server_id = *it;
            free_servers.erase(it);

            request_count[server_id]++;
            busy_servers.emplace(end_time, server_id);
        }

        int max_requests = *max_element(request_count.begin(), request_count.end());
        vector<int> busiest;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                busiest.push_back(i);
            }
        }

        return busiest;
    }
};
