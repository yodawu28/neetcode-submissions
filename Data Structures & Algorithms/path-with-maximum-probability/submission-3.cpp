typedef pair<double, int> pi;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double ans = 0.0;
    
        vector<double> dist(n);
        vector<vector<pi>> adj(n);
        
        priority_queue<pi>pq;
        
        for (int i = 0; i < n; i++) {
            dist[i] = 0;
        }
        
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            double prob = succProb[i];
            
            // undirect edge
            adj[edge[0]].push_back({prob, edge[1]});
            adj[edge[1]].push_back({prob, edge[0]});
        }
        
        // start
        dist[start_node] = 1;
        pq.push({dist[start_node], start_node});
        
        while (!pq.empty()) {
            pi top = pq.top();
            pq.pop();
            
            double cost = top.first;
            int u = top.second;
            
            printf("%f , %d\n", cost, u);
            
            for (int i = 0; i < adj[u].size(); i++) {
                double w = adj[u][i].first;
                int v = adj[u][i].second;
                
                double t = w * cost;
                if (t > dist[v]) {
                    dist[v] = t;
                    pq.push({dist[v], v});
                }
            }
        }
        
        ans = dist[end_node];
        
        return ans;
    }
};