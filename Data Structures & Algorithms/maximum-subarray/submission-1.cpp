class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int L = 0, R = 0;
        int maxSum = nums[R];

        int currSum = 0;

        while (R < nums.size()) {
            if (currSum < 0) {
                L = R;
                currSum = 0;
            }

            currSum += nums[R];
            maxSum = max(currSum, maxSum);
            R++;
        }

        return maxSum;
    }
};
