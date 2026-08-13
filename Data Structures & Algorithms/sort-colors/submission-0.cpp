class Solution {
public:
    void sortColors(vector<int>& nums) {
        int bucket[3] = {0,0,0};
    
        for (int i = 0 ; i < nums.size(); i++) {
            bucket[nums[i]] += 1;
        }
        
        int i = 0;
        for (int b = 0; b < 3; b++) {
            for (int j = 0; j < bucket[b]; j++) {
                nums[i] = b;
                i++;
            }
        }
    }
};