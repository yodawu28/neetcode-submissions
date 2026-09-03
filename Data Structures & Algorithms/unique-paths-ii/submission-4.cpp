class Solution {
public:
    int m, n;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        long long dp[105][105];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }

        if (obstacleGrid[m-1][n-1] == 0) {
            dp[m-1][n-1] = 1;
        }

        for (int i = m-2; i > -1; i--) {
            if (obstacleGrid[i][n-1] == 0) {
                dp[i][n-1] += dp[i+1][n-1];
            }
        }

        for (int i = n-2; i > -1; i--) {
            if (obstacleGrid[m-1][i] == 0) {
                dp[m-1][i] += dp[m-1][i+1];
            }
        }

        for (int i = m-2; i > -1; i--) {
            for (int j = n-2; j > -1; j--) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }

        return dp[0][0];
    }
};