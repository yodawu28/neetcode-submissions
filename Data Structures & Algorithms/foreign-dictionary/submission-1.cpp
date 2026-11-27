class Solution {
public:
    unordered_map<char, vector<int>> adj;
    unordered_map<char, int> visited;
    string ans = "";
    bool isCycle = false;

    struct Edge {
        char u;
        char v;

        Edge(char _u, char _v) : u(_u), v(_v) {}

        // So sánh có hướng: u -> v khác với v -> u
        bool operator==(const Edge &edge) const {
            return u == edge.u && v == edge.v;
        }
    };

    struct EdgeHash {
        size_t operator()(const Edge &edge) const {
            size_t h1 = hash<char>{}(edge.u);
            size_t h2 = hash<char>{}(edge.v);
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };

    void dfs(char u) {
        for (char v: adj[u]) {
            if (visited[v] == 0) {
                visited[v] = 1;
                dfs(v);
            } else if (visited[v] == 1) {
                isCycle = true;
            }
        }
        visited[u] = 2;
        ans += u;
    }


    string foreignDictionary(vector<string>& words) {
        adj.clear();
        visited.clear();
        ans = "";
        isCycle = false;
        
        for (int i = 0; i < 26; i++) {
            adj['a' + i] = {};
            visited['a' + i] = 0;
        }
        
        int n = words.size();
        
        unordered_set<char> vertex;
        
        unordered_set<Edge, EdgeHash> edges;
        
        for (int i = 0; i < n; i++) {
            for (char c: words[i]) {
                vertex.insert(c);
            }
        }
        
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            bool isDiff = false;
            
            int len = min(s1.length(), s2.length());
            for (int k = 0; k < len; k++) {
                if (s1[k] != s2[k]) {
                    Edge edge = Edge(s1[k], s2[k]);
                    edges.insert(edge);
                    isDiff = true;
                    break;
                }
            }
            
            if (!isDiff && s1.length() > s2.length()) {
                return ans;
            }
        }
        
        for (Edge edge: edges) {
            adj[edge.u].push_back(edge.v);
        }
        
        for (char c: vertex) {
            if (visited[c] == 0) {
                visited[c] = 1;
                dfs(c);
                
                if (isCycle) {
                    ans = "";
                    return ans;
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        cout << ans << endl;
        
        return ans;
    }
};
