class Graph {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    Graph() {}

    void addEdge(int src, int dst) {
        auto it = graph.find(src);
        if (it == graph.end()) {
            graph[src] = {};
        }
        graph[src].push_back(dst);
    }

    bool removeEdge(int src, int dst) {
        auto it = graph.find(src);
        if (it == graph.end()) {
            return false;
        }

        auto it1 = find(graph[src].begin(), graph[src].end(), dst);
        if (it1 == graph[src].end()) {
            return false;
        }
        graph[src].erase(it1);
        return true;
    }

    bool hasPath(int src, int dst) {
        visited.clear();
        visited.insert(src);
        int count = 0;
        dfs(src, dst, count);
        return count > 0;
    }

    void dfs(int src, int dst, int &count) {
        if (src == dst) {
            count += 1;
            return;
        }

        for(int i = 0; i < graph[src].size(); i++) {
            auto it = visited.find(graph[src][i]);
            if (it == visited.end()) {
                visited.insert(graph[src][i]);
                dfs(graph[src][i], dst, count);
            }
        }
    }
};
