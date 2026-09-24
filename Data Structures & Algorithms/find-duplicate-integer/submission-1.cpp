class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int slow = 0;
        int fast = 0;

        while (fast < n && nums[fast] < n) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast) {
                int slow2 = 0;
                while (slow < n && slow2 < n) {
                    slow = nums[slow];
                    slow2 = nums[slow2];
                    if (slow == slow2) {
                        break;
                    }
                }
                return slow2;
            }
        }

        return -1;
    }
};
