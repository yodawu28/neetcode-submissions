typedef pair<int, int> pi;

class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> ans;

        vector<int> dist;
        vector<vector<pi>> adj;
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for (int i = 0; i < n; i++) {
            dist.push_back(INT_MAX);
            adj.push_back({});
        }

        for (int i = 0; i < edges.size(); i++) {
            vector<int> item = edges[i];
            adj[item[0]].push_back({item[1], item[2]});
        }

        dist[src] = 0;
        pq.push({dist[src], src});

        while (!pq.empty()) {
            pi top = pq.top();
            pq.pop();

            int cost = top.first;
            int u = top.second;

            if (cost > dist[u]) {
                continue;
            }

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            dist[i] = dist[i] != INT_MAX ? dist[i] : -1;
            ans[i] = dist[i];
        }

        return ans;
    }
};
