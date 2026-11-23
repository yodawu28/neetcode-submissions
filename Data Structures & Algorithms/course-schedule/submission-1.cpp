class Solution {
public:
    vector<int> visited;
    vector<vector<int>> adj;
    bool isCycle;

    void dfs(int u) {
        for (int v: adj[u]) {
            if (visited[v] == 0) {
                visited[v] = 1;
                dfs(v);
            } else if (visited[v] == 1) {
                isCycle = true;
            }
            visited[v] = 2;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.clear();
        adj.clear();
        isCycle = false;

        for (int i = 0; i < numCourses; i++) {
            visited.push_back(0);
            adj.push_back({});
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                dfs(i);
                visited[i] = 2;
            }
        }

        return !isCycle;
    }
};
