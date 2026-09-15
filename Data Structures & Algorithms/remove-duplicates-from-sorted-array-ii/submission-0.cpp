class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int read = 0, write = 0;
    
        while (read < nums.size()) {
            int current = nums[read];
            
            if (write < 2) {
                write++;
            } else if (!(current == nums[write-1] && current == nums[write-2])) {
                nums[write] = current;
                write++;
            }
            
            read++;
        }
        
        
        return write;
    }
};