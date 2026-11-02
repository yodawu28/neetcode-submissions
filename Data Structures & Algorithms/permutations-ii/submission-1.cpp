class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;
    unordered_map<int, int> m;

    void helper(int n) {
        if (subset.size() >= n) {
            ans.push_back(subset);
            return;
        }

        for (auto item: m) {
            if (item.second > 0) {
                subset.push_back(item.first);
                m[item.first]--;
                helper(n);
                subset.pop_back();
                m[item.first]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        subset.clear();
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        
        helper(nums.size());
        return ans;
    }
};