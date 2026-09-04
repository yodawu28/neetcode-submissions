class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> sumArr;
        vector<int> limitArr;
        sumArr.push_back(nums[0]);
        limitArr.push_back(nums[0]);
        int maxLimit = limitArr[0];
        for (int i = 1; i < nums.size(); i++) {
            if (maxLimit < sumArr[i-1] + nums[i]) {
                maxLimit =sumArr[i-1] + nums[i];
            }
            sumArr.push_back(sumArr[i-1] + nums[i]);
            limitArr.push_back(maxLimit);
        }
        
        int L = 0, R = 0;
        int currSum = 0;
        int maxSum1 = nums[0];
        int size = nums.size() - 1;
        int maxSum2 = sumArr[size];
        
        while (R < nums.size()) {
            if (currSum < 0) {
                currSum = 0;
                L = R;
            }
            
            currSum += nums[R];
            maxSum1 = max(maxSum1, currSum);

            if (R > 1) {
                int subSum = sumArr[size] - sumArr[R-1];
                int sumCircular = subSum + limitArr[R-2];
                maxSum2 = max(maxSum2, sumCircular);
            }
            
            R++;
        }
        return max(maxSum1, maxSum2);
    }
};