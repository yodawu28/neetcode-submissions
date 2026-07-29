class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> my_set;
        bool is_duplicate = false;

        for (int i = 0; i < nums.size(); i++) {
            if (my_set.find(nums[i]) != my_set.end()) {
                is_duplicate = true;
                break;
            }
            my_set.insert(nums[i]);
        }

        return is_duplicate;
    }
};
