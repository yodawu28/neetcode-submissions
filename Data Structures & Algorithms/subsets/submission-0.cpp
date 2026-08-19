class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> start;
        ans.push_back(start);
        
        for (int i = 0; i < nums.size(); i++) {
            int size = ans.size();
            for (int j = 0; j < size; j++) {
                vector<int> tmp(ans[j]);
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
