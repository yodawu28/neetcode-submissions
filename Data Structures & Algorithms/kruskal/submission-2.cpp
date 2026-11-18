class UniFind {
public:
    vector<int> parents;
    vector<int> ranks;

    UniFind(int n) {
        for (int i = 0; i < n; i++) {
            parents.push_back(i);
            ranks.push_back(0);
        }
    }

    int find (int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
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

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        int ans = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            pq.push({w, {u, v}});
        }

        UniFind uniFind = UniFind(n);

        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();

            int cost = top.first;
            pi edge = top.second;

            if (uniFind._union(edge.first, edge.second)) {
                cout << "cost: " << cost << endl;
                cout << "u: " << edge.first << ", v: " << edge.second << endl;
                cout << endl;
                ans += cost;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i == uniFind.parents[i]) {
                cnt++;
            }
        }

        if (cnt > 1) {
            return -1;
        }

        return ans;
    }
};
