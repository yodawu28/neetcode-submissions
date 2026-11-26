class Solution {
public:
    vector<int> visited;
    vector<vector<int>> adj;
    unordered_map<int, unordered_set<int>> parents;
    unordered_set<int> path;

    void dfs(int u) {
        for (int v : adj[u]) {
            if (visited[v] == 0) {
                visited[v] = 1;
                dfs(v);
            }
        }
        path.insert(u);
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;

        for (int i = 0; i < numCourses; i++) {
            visited.push_back(0);
            adj.push_back({});
        }

        for (vector<int> item : prerequisites) {
            int u = item[0];
            int v = item[1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < numCourses; i++) {
            fill(visited.begin(), visited.end(), 0);
            visited[i] = 1;
            dfs(i);
            parents[i] = path;
            path.clear();
        }
        
        for (vector<int> item: queries) {
            int u = item[0];
            int v = item[1];
            
            bool isOk = false;
            auto it = parents[u].find(v);
            if (it != parents[u].end()) {
                isOk = true;
            }
            
            ans.push_back(isOk);
        }
        return ans;
    }
};