class Solution {
public:
    int visited[1005];
    vector<vector<int>> adj;

    bool dfs(int v) {
        visited[v] = 1;
        bool isOk = true;
        for (int i = 0; i < adj[v].size(); i++) {
            if (visited[adj[v][i]] == 1) {
                return false;
            }

            if (visited[adj[v][i]] == 0) {
                isOk = isOk && dfs(adj[v][i]);
            }
        }
        visited[v] = 2;
        return isOk;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            visited[i] = 0;
            adj.push_back({});
        }    

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        bool isOk = true;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                isOk = isOk && dfs(i);
            }
        }

        if (isOk) {
            // check we travel all node
            for (int i = 0; i < numCourses; i++) {
                if (visited[i] == 0) {
                    return false;
                }
            }
        }

        return isOk;
    }
};
