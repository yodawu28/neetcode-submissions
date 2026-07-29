class Solution {
public:

    int search(vector<int> &nums, int target, int start)
    {
        for (int i = start; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int n_target = target - nums[i];

            int idx = search(nums, n_target, i+1);
            if (idx != -1 && idx != i)
            {
                ans.push_back(i);
                ans.push_back(idx);
                break;
            }
        }

        return ans;
    }
};
