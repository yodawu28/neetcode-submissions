class Solution {
public:
    int m, n;
    queue<pair<int, int>> q;
    bool visited[105][105];

    bool check(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r > m - 1) {
            return false;
        }

        if (c < 0 || c > n - 1) {
            return false;
        }

        if (grid[r][c] == 1) {
            return false;
        }

        if (visited[r][c]) {
            return false;
        }

        return true;
    }

    int bfs(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] == 1) {
            return -1;
        }

        int directions[8][2] = {
            {0,1}, {1,0}, {-1,0}, {0,-1},
            {1,1}, {-1, 1}, {1, -1}, {-1,-1}
        };

        int length = 1;

        q.push(pair<int,int>(r,c));
        visited[r][c] = true;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                if (x == m -1 && y == n-1) {
                    return length;
                }

                for (int j = 0; j < 8; j++) {
                    int new_x = x + directions[j][0];
                    int new_y = y + directions[j][1];

                    if (check(grid, new_x, new_y)) {
                        q.push(pair<int, int>(new_x, new_y));
                        visited[new_x][new_y] = true;
                    }
                }
            }

            length++;
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        return bfs(grid, 0, 0);
    }
};