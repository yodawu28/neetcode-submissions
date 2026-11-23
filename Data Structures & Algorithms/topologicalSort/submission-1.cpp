class Vertex {
public:
    int id;
    int visited;
    vector<int> adj;
    
    Vertex() {};
    
    Vertex(int _id, int _visited) {
        id = _id;
        visited = _visited;
    }
    
    bool operator<(const Vertex vertex) const {
        return visited < vertex.visited;
    }
    
    bool operator>(const Vertex vertex) const {
        return visited > vertex.visited;
    }
};

class Solution {
public:
    bool isCycle = false;
    unordered_map<int, Vertex> m;
    vector<int> ans;

    void dfs(Vertex u) {
        for (int id: u.adj) {
            Vertex v = m[id];
            if (m[id].visited == 0) {
                m[id].visited = 1;
                dfs(m[id]);
            } else if (m[id].visited == 1) {
                isCycle = true;
            }
            m[id].visited = 2;
        }
        ans.push_back(u.id);
    }

    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        ans.clear();
        m.clear();
        
        for (int i = 0; i < n; i++) {
            m[i] = Vertex(i, 0);
        }
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            m[u].adj.push_back(v);
        }
        
        for (int i = 0; i < n; i++) {
            if (m[i].visited == 0) {
                m[i].visited = 1;
                dfs(m[i]);
                if (isCycle) {
                    ans.clear();
                    return ans;
                }
                m[i].visited = 2;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
