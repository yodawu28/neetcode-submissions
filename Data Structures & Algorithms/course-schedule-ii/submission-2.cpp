class Solution {
public:
    vector<int> ans;
    vector<int> visited;
    vector<vector<int>> adj;
    bool isCycle = false;

    void dfs(int u) {
        for (int v : adj[u]) {
            if (visited[v] == 0) {
                visited[v] = 1;
                dfs(v);
            } else if (visited[v] == 1) {
                isCycle = true;
                return;
            }

            visited[v] = 2;
        }
        ans.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ans.clear();
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

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                dfs(i);

                if (isCycle) {
                    ans.clear();
                    return ans;
                }

                visited[i] = 2;
            }
        }
        return ans;
    }
};
