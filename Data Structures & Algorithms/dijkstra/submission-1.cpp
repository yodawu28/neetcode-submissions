typedef pair<int, int> pi;
class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> dist;
    
        unordered_map<int, vector<pi>> adj;
        
        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
            adj[i] = {};
        }
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
        }
        
        priority_queue<pi, vector<pi>, greater<pi>>pq;
        
        dist[src] = 0;
        
        pq.push({dist[src], src});
        
        while (!pq.empty()) {
            int cost = pq.top().first;
            int u = pq.top().second;
            
            pq.pop();
            
            if (cost > dist[u]) {
                continue;
            }
            
            for (auto item : adj[u]) {
                int v = item.first;
                int w = item.second;
                
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for (auto item: dist) {
            if (item.second == INT_MAX) {
                dist[item.first] = -1;
            }
        }
        
        return dist;
    }
};
