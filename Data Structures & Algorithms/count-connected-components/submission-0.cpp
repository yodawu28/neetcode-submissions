class UniFind {
public:
    unordered_map<int, int> parents;
    unordered_map<int, int> ranks;
    
    UniFind(int n) {
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 0;
        }
    }
    
    int find(int x) {
        int root = parents[x];
        if (root != x) {
            return root = find(parents[root]);
        }
        return root;
    }
    
    bool _union(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        
        if (parentX == parentY) {
            return false;
        }
        
        if (ranks[x] < ranks[y]) {
            parents[parentX] = parentY;
        } else if (ranks[x] > ranks[y]) {
            parents[parentY] = parentX;
        } else {
            parents[parentY] = parentX;
            ranks[parentX]++;
        }
        
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
    
        UniFind *uf = new UniFind(n);
        
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            uf->_union(edge[0], edge[1]);
        }
        
        for (int i = 0; i < n; i++) {
            int parent = uf->parents[i];
            if (parent == i) {
                cnt++;
            }
        }
        
        return cnt;
    }
};
