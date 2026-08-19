class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void run(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            ans.push_back(curr);
            return;
        }

        // choose idx
        curr.push_back(nums[idx]);
        run(nums, idx + 1);
        // backtrack
        curr.pop_back();
        // not choose
        run(nums, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        run(nums, 0);
        return ans;
    }
};
