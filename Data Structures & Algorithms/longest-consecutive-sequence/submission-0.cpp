class UniFind {
public:
    unordered_map<int, int> parents;
    unordered_map<int, int> ranks;
    
    UniFind(const unordered_set<int> &mySet) {
        for (int num: mySet) {
            parents[num] = num;
            ranks[num] = 0;
        }
    }
    
    int find(int x) {
        int root = parents[x];
        if (root != parents[root]) {
            return parents[x] = find(root);
        }
        return root;
    }
    
    bool _union(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        
        if (parentX == parentY) {
            return false;
        }
        
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
    int longestConsecutive(vector<int>& nums) {
        int cnt = 0;
    
        unordered_set<int> mySet(nums.begin(), nums.end());
        
        unordered_map<int, int> seqSize;
        
        vector<vector<int>> edges;
        
        UniFind* uf = new UniFind(mySet);
        
        for (auto num: mySet) {
            int parent = num - 1;
            auto it = mySet.find(parent);
            if (it != mySet.end()) {
                edges.push_back({num, parent});
            }
            seqSize[num] = 0;
        }
        
        for (int i = 0; i < edges.size(); i++) {
            uf->_union(edges[i][1], edges[i][0]);
        }
        
        for (int num: mySet) {
            int parent = uf->find(num);
            seqSize[parent]++;
            cnt = max(cnt, seqSize[parent]);
        }
        
        return cnt;
    }
};
