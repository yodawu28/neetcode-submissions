class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 1, R = heights.size();
        int maxArea = 0;

        while (L < R) {
            int width = R - L;
            int height = min(heights[L-1], heights[R-1]);
            maxArea = max(maxArea, width * height);

            if (heights[L-1] < heights[R-1]) {
                L++;
            } else {
                R--;
            }
        }
        return maxArea;
    }
};
