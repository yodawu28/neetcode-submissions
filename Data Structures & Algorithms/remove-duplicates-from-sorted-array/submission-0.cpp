class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L = 0, R = 1;
    
        int size = nums.size();
        
        while (R < size) {
            while (nums[L] == nums[R] && R < size) {
                int i = R;
                while (i < size) {
                    nums[i-1] = nums[i];
                    i++;
                }
                size--;
            }
            L++;
            R++;
        }

        return size;
    }
};