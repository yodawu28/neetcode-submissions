class Solution {
public:
    map<int, int>m;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int b = target - nums[i];
            auto it = m.find(b);

            if (it != m.end()) {
                ans.push_back(it->second);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }

        return ans;
    }
};
