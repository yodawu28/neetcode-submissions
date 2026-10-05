class UniFind {
public:
    unordered_map<int, int> parents;
    unordered_map<int, int> ranks;
    UniFind(int n) {
        for (int i = 1; i <= n; i++) {
            parents[i] = i;
            ranks[i] = 0;
        }
    }
    
    int find(int x) {
        if (x == parents[x]) {
            return x;
        }
        return find(parents[x]);
    }
    
    bool isSameComponent(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        
        return parentX == parentY;
    }
    
    bool _union(int x, int y) {
        if (isSameComponent(x, y)) {
            return false;
        }
        
        int parentX = find(x);
        int parentY = find(y);
        
        if (ranks[parentX] > ranks[parentY]) {
            parents[parentY] = parentX;
        } else if (ranks[parentX] < ranks[parentY]) {
            parents[parentX] = parentY;
        } else {
            parents[parentY] = parentX;
            ranks[parentX]++;
        }
        
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
    
        int n = edges.size();
        
        UniFind uf = UniFind(n);
        
        for (int i = 0; i < n; i++) {
            vector<int> edge = edges[i];
            if (uf.isSameComponent(edge[0], edge[1])) {
                ans.push_back(edge[0]);
                ans.push_back(edge[1]);
                break;
            }
            uf._union(edge[0], edge[1]);
        }
        
        return ans;
    }
};
