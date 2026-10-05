class UnionFind {
public:
    unordered_map<int, int> parents;
    unordered_map<int, int> ranks;
    int size;
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 0;
        }
        size = n;
    }

    int find(int x) {
        while (x != parents[x]) {
            x = parents[x];
        }
        return x;
    }

    bool isSameComponent(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        return parent_x == parent_y;
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y) {
            return false;
        }

        if (ranks[parent_x] > ranks[parent_y]) {
            parents[parent_y] = parent_x;
        } else if (ranks[parent_x] < ranks[parent_y]) {
            parents[parent_x] = parent_y;
        } else {
            parents[parent_y] = parent_x;
            ranks[parent_x]++;
        }

        size--;

        return true;
    }

    int getNumComponents() {
        // int size = 0;
        // for (auto it : parents) {
        //     if (it.first == it.second) {
        //         size++;
        //     }
        // }
        return size;
    }
};
