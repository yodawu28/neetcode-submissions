class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int amount = 0;

        while (L < R) {
            leftMax = max(leftMax, height[L]);
            rightMax = max(rightMax, height[R]);

            if (leftMax <= rightMax) {
                amount += leftMax - height[L];
                L++;
            } else {
                amount += rightMax - height[R];
                R--;
            }
        }

        return amount;
    }

};
