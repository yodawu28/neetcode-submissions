class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> curr;

    void helper(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            ans.push_back({});
            return;
        }

        helper(nums, idx+1);

        curr = ans;
        ans.clear();

        for (int i = 0; i < curr.size(); i++) {
            for (int j = 0; j <= curr[i].size(); j++) {
                vector<int> v(curr[i]);
                v.insert(v.begin() + j, nums[idx]);
                ans.push_back(v);
            }
        }

        curr.clear();
    }

    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        curr.clear();

        helper(nums, 0);

        return ans;
    }
};
