typedef pair<int, int> pi;
typedef pair<int, pi> pii;

class Solution {
public:
    bool check(int x, int y, int m, int n)
    {
        if (x < 0)
        {
            return false;
        }

        if (y < 0)
        {
            return false;
        }

        if (x > m - 1)
        {
            return false;
        }

        if (y > n - 1)
        {
            return false;
        }

        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dist;

        int t = grid[0][0];

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            dist.push_back({});
            for (int j = 0; j < n; j++)
            {
                dist[i].push_back(INT_MAX);
            }
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[0][0] = t;
        pq.push({dist[0][0], {0, 0}});

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1,0}, {0,-1}};

        while (!pq.empty())
        {
            pii top = pq.top();
            pq.pop();

            int cost = top.first;
            pi point = top.second;
            
            t = max(t, cost);

            if (point.first == m - 1 && point.second == n - 1)
            {
                break;
            }

            if (cost > dist[point.first][point.second])
            {
                continue;
            }

            for (int i = 0; i < directions.size(); i++)
            {
                int n_x = point.first + directions[i][0];
                int n_y = point.second + directions[i][1];

                if (check(n_x, n_y, m, n) && dist[n_x][n_y] > grid[n_x][n_y])
                {
                    dist[n_x][n_y] = grid[n_x][n_y];
                    pq.push({dist[n_x][n_y], {n_x, n_y}});
                }
            }
        }

        return t;
    }
};
