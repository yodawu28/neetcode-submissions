class Solution {
public:
    vector<int> visited;
    vector<vector<int>> adj;
    vector<int> path;
    bool isFind = false;

    void dfs(int start, int end) {
        for (int v : adj[start]) {
            if (v == end) {
                isFind = true;
            }

            if (visited[v] == 0) {
                visited[v] = 1;
                dfs(v, end);
            }
        }

        path.push_back(start);
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;

        visited.clear();
        adj.clear();

        for (int i = 0; i < numCourses; i++) {
            visited.push_back(0);
            adj.push_back({});
        }

        for (vector<int> item : prerequisites) {
            int u = item[0];
            int v = item[1];
            adj[u].push_back(v);
        }

        for (vector<int> q : queries) {
            int u = q[0];
            int v = q[1];
            fill(visited.begin(), visited.end(), 0);
            visited[u] = 1;
            path.clear();
            isFind = false;

            dfs(u, v);
            if (!isFind) {
                ans.push_back(false);
            } else {
                reverse(path.begin(), path.end());
                int a1 = 0, a2 = 0;
                for (int i = 0; i < path.size(); i++) {
                    if (path[i] == u) {
                        a1 = i;
                    }
                    
                    if (path[i] == v) {
                        a2 = i;
                    }
                }
                
                bool ok = a1 < a2;
                ans.push_back(ok);
            }
        }

        return ans;
    }
};