class Solution {
public:
    set<int> st;
    bool hasDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            auto it = st.find(nums[i]);
            if (it == st.end()) {
                st.insert(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};