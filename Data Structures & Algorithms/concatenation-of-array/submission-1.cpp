class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>::iterator it;
        it = nums.begin();
        nums.insert(it, nums.begin(), nums.end());
        return nums;
    }
};