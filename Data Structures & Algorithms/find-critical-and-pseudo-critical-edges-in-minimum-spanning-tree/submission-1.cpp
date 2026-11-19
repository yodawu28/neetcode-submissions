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

    int find(int x) {
        if (x != parents[x]) {
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

class Edge {
  public:
    int idx;
    int u;
    int v;
    int w;
    Edge(int _idx, int _u, int _v, int _w) {
        idx = _idx;
        u = _u;
        v = _v;
        w = _w;
    }

    bool operator<(const Edge &edge) const { return w < edge.w; }

    bool operator>(const Edge &edge) const { return w > edge.w; }

    void info() {
        cout << "id: " << idx;
        cout << ", u: " << u;
        cout << ", v: " << v;
        cout << ", w: " << w << endl;
    }
};

class Solution {
public:
    int buildMST(int n, vector<Edge> &edges) {
        int weight = 0;

        UniFind uFind = UniFind(n);

        for (int i = 0; i < edges.size(); i++) {
            Edge top = edges[i];

            if (uFind._union(top.u, top.v)) {
                weight += top.w;
            }
        }

        // check mst
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (uFind.parents[i] == i) {
                cnt++;
            }
        }

        if (cnt > 1)
            return -1;

        return weight;
    }

    int buildMST(int n, vector<Edge> &edges, int idx, bool isChoose) {
        int weight = 0;

        UniFind uFind = UniFind(n);
        
        if (isChoose) {
            uFind._union(edges[idx].u, edges[idx].v);
            weight += edges[idx].w;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == idx) {
                continue;
            }
            
            Edge top = edges[i];

            if (uFind._union(top.u, top.v)) {
                weight += top.w;
            }
        }

        // check mst
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (uFind.parents[i] == i) {
                cnt++;
            }
        }

        if (cnt > 1)
            return -1;

        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;

        vector<int> critical;
        vector<int> pseudo;

        vector<Edge> nEdges;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            Edge edge = Edge(i, u, v, w);
            nEdges.push_back(edge);
        }

        sort(nEdges.begin(), nEdges.end());

        int minWeight = buildMST(n, nEdges);
        
        for (int i = 0; i < nEdges.size(); i++) {
            // choose edge
            int weight = buildMST(n, nEdges, i, true);
            if (weight == -1) {
                continue;
            }
            
            if (weight == minWeight) {
                int weight2 = buildMST(n, nEdges, i, false);
                if (weight2 == -1 || weight2 > minWeight) {
                    critical.push_back(nEdges[i].idx);
                } else if (weight2 == minWeight) {
                    pseudo.push_back(nEdges[i].idx);
                }
            }
        }

        ans.push_back(critical);
        ans.push_back(pseudo);

        return ans;
    }
};