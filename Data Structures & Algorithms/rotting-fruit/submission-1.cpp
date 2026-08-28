class Solution {
public:
    int m, n;
    int visited[15][15];
    queue<pair<int, int>> q;
    vector<pair<int, int>> path;

    bool check(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r > m - 1) {
            return false;
        }

        if (c < 0 || c > n - 1) {
            return false;
        }

        if (grid[r][c] != 1) {
            return false;
        }

        if (visited[r][c]) {
            return false;
        }

        return true;
    }

    int bfs(vector<vector<int>>& grid) {
        int length = 0;
        
        for (int i = 0; i < path.size(); i++) {
            pair<int, int> p = path[i];
            int r = p.first;
            int c = p.second;

            q.push(pair<int,int>(r,c));
            visited[r][c] = true;
        }

        int direction[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;

                for (int j = 0; j < 4; j++) {
                    int new_x = x + direction[j][0];
                    int new_y = y + direction[j][1];

                    if (check(grid, new_x, new_y)) {
                        q.push(pair<int, int>(new_x, new_y));
                        grid[new_x][new_y] = 2;
                        visited[new_x][new_y] = true;
                    }
                }
            }
            if (!q.empty())
                length++;
        }

        return length;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
                if (grid[i][j] == 2) {
                    path.push_back(pair<int, int>(i, j));
                }
            }
        }

        int length = bfs(grid);

        int freshCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) {
            return length;
        }

        return -1;
    }
};
