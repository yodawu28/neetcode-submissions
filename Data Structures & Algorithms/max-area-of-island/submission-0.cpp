class Solution {
public:
    vector<vector<bool>> visited;
    int m = 0;
    int n = 0;

    bool check(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r > m - 1) {
            return false;
        }
        
        if (c < 0 || c > n - 1) {
            return false;
        }
        
        if (grid[r][c] == 0) {
            return false;
        }
        
        if (visited[r][c]) {
            return false;
        }
        
        return true;
    }

    void run(vector<vector<int>>& grid, int r, int c, int &count) {
        visited[r][c] = true;
        
        if (check(grid, r - 1, c)) {
            count += 1;
            run(grid, r - 1, c, count);
        }

        if (check(grid, r + 1, c)) {
            count += 1;
            run(grid, r + 1, c, count);
        }

        if (check(grid, r, c - 1)) {
            count += 1;
            run(grid, r, c - 1, count);
        }

        if (check(grid, r, c + 1)) {
            count += 1;
            run(grid, r, c + 1, count);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
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
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count = 1;
                    run(grid, i, j, count);
                    ans = max(count, ans);
                }
            }
        }

        return ans;    
    }
};
