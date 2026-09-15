class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L = 0, R = 1;
    
        while (R < nums.size()) {
            while (R < nums.size()) {
                if (nums[L] != nums[R]) {
                    L++;
                    nums[L] = nums[R];
                    break;
                }
                R++;
            }
            R++;
        }

        return L + 1;
    }
};