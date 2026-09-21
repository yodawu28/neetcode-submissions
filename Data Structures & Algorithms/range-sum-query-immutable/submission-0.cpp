class NumArray {
public:
    vector<int> sumPrefix;
    NumArray(vector<int>& nums) {
        int prefix = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            sumPrefix.push_back(prefix);
        }
    }
    
    int sumRange(int left, int right) {
        int prefixLeft = 0;
        if (left > 0) {
            prefixLeft = sumPrefix[left - 1];
        }

        return sumPrefix[right] - prefixLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */