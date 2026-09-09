class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 100005;
        
        vector<int> sums;
        sums.push_back(0);
        
        for (int i = 0; i < nums.size(); i++) {
            sums.push_back(sums[i] + nums[i]);
        }
        
        if (sums[sums.size()-1] < target) {
            return 0;
        }
        
        int low = 1;
        int high = sums.size() - 1;
        while (low <= high) {
            int L = low;
            int R = high;
            
            while (L < R) {
                int mid = (L + R) / 2;
                if (sums[mid] - sums[low-1] < target) {
                    L = mid+1;
                } else {
                    R = mid;
                }
            }
            
            if (sums[R] >= sums[low-1] + target) {
                ans = min(ans, R - low + 1);
            }
            
            low++;
        }
        
        return ans;
    }
};