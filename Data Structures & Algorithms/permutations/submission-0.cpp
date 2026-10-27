class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        ans.push_back({});
        vector<vector<int>> next;
        
        
        for (int i = 0; i < nums.size(); i++) {
            next = ans;
            ans.clear();
            int m = next.size();
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= next[j].size(); k++) {
                    vector<int> v = next[j];
                    v.insert(v.begin() + k, nums[i]);
                    ans.push_back(v);
                }
            }
        }
        
        return ans;
    }
};
