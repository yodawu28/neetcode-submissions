class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        long long dp[1005][1005];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = m-1; i > -1; i--) {
            for (int j = n-1; j > -1; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};
