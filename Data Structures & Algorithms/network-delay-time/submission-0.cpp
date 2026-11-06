typedef pair<int, int> pi;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist;
        vector<vector<pi>> adj;

        for (int i = 0; i <= n; i++) {
            dist.push_back(INT_MAX);
            adj.push_back({});
        }

        for (int i = 0; i < times.size(); i++) {
            vector<int> item = times[i];

            int u = item[0];
            int v = item[1];
            int t = item[2];

            adj[u].push_back({v, t});
        }

        dist[k] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({dist[k], k});

        while (!pq.empty()) {
            pi top = pq.top();
            pq.pop();

            int cost = top.first;
            int u = top.second;

            if (cost > dist[u]) {
                continue;
            }

            for (int i = 0; i < adj[u].size(); i++) {
                pi item = adj[u][i];

                int v = item.first;
                int w = item.second;

                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = INT_MIN;

        for (int i = 1; i <= n; i++) {
            ans = max(ans, dist[i]);
        }

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};
