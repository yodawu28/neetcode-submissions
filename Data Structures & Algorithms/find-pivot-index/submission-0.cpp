class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
        int sum = 0;
        prefix.push_back(0);
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefix.push_back(sum);
        }
        
        int n = prefix.size() - 1;
        for (int i = 1; i < prefix.size(); i++) {
            int left = prefix[i-1];
            int right = prefix[n] - prefix[i];
            if (left == right) {
                return i - 1;
            }
        }
        
        return -1;
    }
};