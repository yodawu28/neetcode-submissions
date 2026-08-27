class Solution {
public:
    vector<vector<int>> visited;
    int m = 0;
    int n = 0;

    bool check(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r > m - 1) {
            return false;
        }

        if (c < 0 || c > n - 1) {
            return false;
        }

        if (visited[r][c]) {
            return false;
        }

        if (grid[r][c] == '0') {
            return false;
        }

        return true;
    }

    void run(vector<vector<char>>& grid, int r, int c) {
        visited[r][c] = true;

        if (check(grid, r - 1, c)) {
            run(grid, r-1, c);
        }

        if (check(grid, r + 1, c)) {
            run(grid, r + 1, c);
        }

        if (check(grid, r, c - 1)) {
            run(grid, r, c - 1);
        }

        if (check(grid, r, c + 1)) {
            run(grid, r, c + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
    
        m = grid.size();
        n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            visited.push_back({});
            for (int j = 0; j < n; j++) {
                visited[i].push_back(false);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    run(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
