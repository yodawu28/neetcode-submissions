class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;

        int start = -1;
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1 && start == -1)
            {
                start = i;
            }
            else if (nums[i] == 0 && start != -1)
            {
                res = max(res, i - start);
                start = -1;
            }
        }

        if (start != -1 && nums[i-1] == 1)
        {
            res = max(res, i - start);
        }

        return res;
    }
};