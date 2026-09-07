class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int L = 0, R = 1;
    
        unordered_map<int, int> m;
        m[nums[L]] = L;
        
        while (R < nums.size()) {
            auto it = m.find(nums[R]);
            if (it != m.end() && abs(m[nums[R]] - R) <= k) {
                return true;
            }
            
            m[nums[R]] = R;
            R++;
        }
        
        return false;
    }
};