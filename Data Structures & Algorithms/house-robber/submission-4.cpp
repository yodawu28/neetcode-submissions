class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
    
        int dp[n+1];
        
        for (int i = 0; i <= n; i++) {
            dp[i] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                dp[i] = max(dp[i-2] + nums[i - 1], dp[i-1]);
            } else {
                dp[i] = max(nums[i-1], dp[i-1]);
            }
        }
        
        return dp[n];
    }
};
