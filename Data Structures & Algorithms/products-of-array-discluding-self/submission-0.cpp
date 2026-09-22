class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
    
        vector<int> left;
        vector<int> right;
        
        int t = 1;
        for (int i = 0; i < nums.size(); i++) {
            t *= nums[i];
            left.push_back(t);
        }
        
        t = 1;
        for (int i = nums.size() - 1; i > -1; i--) {
            t *= nums[i];
            right.push_back(t);
        }
        reverse(right.begin(), right.end());

        for (int i = 0; i < nums.size(); i++) {
            int L = 1;
            if (i > 0) {
                L = left[i-1];
            }
            
            
            int R = 1;
            if (i < nums.size() - 1) {
                R = right[i+1];
            }
            
            ans.push_back(L * R);
        }

        return ans;
    }
};
