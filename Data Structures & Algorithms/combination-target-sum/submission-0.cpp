class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    int currSum = 0;

    void run(vector<int>& nums, int currIdx, int target) {
        if (currSum == target) {
            ans.push_back(v);
            return;
        }
        
        if (currIdx >= nums.size() || currSum > target) {
            return;
        }
        
        // choose currIdx
        v.push_back(nums[currIdx]);
        currSum += nums[currIdx];
        
        run(nums, currIdx, target);
        
        currSum -= nums[currIdx];
        v.pop_back();
        
        //
        run(nums, currIdx + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        run(nums, 0, target);
        return ans;
    }
};
