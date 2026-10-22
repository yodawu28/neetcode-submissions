class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void helper(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            ans.push_back(subset);
            return;
        }

        // choose i
        subset.push_back(nums[index]);
        helper(nums, index+1);
        subset.pop_back();

        // not choose i
        while (index < nums.size() - 1 && nums[index] == nums[index + 1]) {
            index++;
        }
        helper(nums, index+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        subset.clear();

        sort(nums.begin(), nums.end());

        helper(nums, 0);

        return ans;    
    }
};
