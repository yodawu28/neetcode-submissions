class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0, sum = 0;
        int R = 0;
        
        int ans = 100005;
        
        while (R < nums.size()) {
            while (sum + nums[R] >= target) {
                ans = min(ans, abs(R - L) + 1);
                sum -= nums[L];
                L++;
            }
            sum += nums[R];
            R++;
        }
        
        if (ans == 100005) {
            ans = 0;
        } else {
            if (sum >= target) {
                ans = min(ans, abs(R - L));
            }
        }
        
        return ans;
    }
};