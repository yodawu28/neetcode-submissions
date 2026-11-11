typedef pair<int,int> pi;

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        int ans = 0;
    
        vector<int>visited(n);
        vector<vector<pi>> adj(n);
        
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }
        
        for (int i = 0; i < edges.size(); i++) {
            vector<int> item = edges[i];
            
            int u = item[0];
            int v = item[1];
            int w = item[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        pq.push({0,0});
        
        while (!pq.empty())
        {
            pi top = pq.top();
            pq.pop();
            
            int cost = top.first;
            int u = top.second;
            
            if (visited[u]) {
                continue;
            }
            
            ans += cost;
            visited[u] = true;
            
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if (!visited[v]) {
                    pq.push({w, v});
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return -1;
            }
        }
        
        return ans;
    }
};

