class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;

        int L = 0;
        int R = numbers.size() - 1;

        while (L < R) {
            int sum = numbers[L] + numbers[R];
            if (sum == target) {
                ans.push_back(L+1);
                ans.push_back(R+1);
                break;
            } else if (sum > target) {
                R--;
            } else {
                L++;
            }
        }

        return ans;
    }
};
