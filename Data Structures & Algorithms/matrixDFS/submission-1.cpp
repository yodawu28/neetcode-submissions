class Solution {
public:
    vector<vector<int>> visited;
    int m = 0;
    int n = 0;

    bool check(vector<vector<int>>& grid,int row, int col) {
        if (row < 0 || row > m - 1) {
            return false;
        }
        
        if (col < 0 || col > n-1) {
            return false;
        }
        
        if (grid[row][col] == 1) {
            return false;
        }
        
        if (visited[row][col]) {
            return false;
        }
        
        return true;
    }

    void run(vector<vector<int>>& grid, int row, int col, int &count) {
        if (row == m - 1 && col == n-1) {
            count++;
            return;
        }
        
        if (check(grid, row, col)) {
            visited[row][col] = true;
        
            if (check(grid, row-1, col)) {
                run(grid, row - 1, col, count);
            }
            
            if (check(grid, row + 1, col)) {
                run(grid, row + 1, col, count);
            }
            
            if (check(grid, row, col-1)) {
                run(grid, row , col - 1, count);
            }
            
            if (check(grid, row, col + 1)) {
                run(grid, row, col + 1, count);
            }
            
            visited[row][col] = false;
        }
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            visited.push_back({});
            for (int j = 0; j < n; j++) {
                visited[i].push_back(false);
            }
        }
        
        int count = 0;
        
        run(grid, 0, 0, count);
        
        return count;
    }
};
