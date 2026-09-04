class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> sumArr;
        sumArr.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            sumArr.push_back(sumArr[i-1] + nums[i]);
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
                int i = 0;
                int subSum = sumArr[size] - sumArr[R-1];
                // cout << "subSum: " << subSum << endl;
                while (i <= R -2) {
                    int sumCircular = subSum + sumArr[i];
                    // cout << "sumCircular: " << sumCircular << endl;
                    maxSum2 = max(maxSum2, sumCircular);
                    i++;
                }
            }
            
            R++;
        }
        
        // cout << maxSum1 << endl;
        // cout << maxSum2 << endl;
        
        return max(maxSum1, maxSum2);
    }
};