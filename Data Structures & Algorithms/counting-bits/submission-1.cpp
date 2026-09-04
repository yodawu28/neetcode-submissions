class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        if (n == 0) {
            return ans;
        }

        ans[0] = 0;
        ans[1] = 1;

        if (n == 1) {
            return ans;
        }

        ans[2] = 1;
        if (n == 2) {
            return ans;
        }

        for (int i = 3; i <= n; i++) {
            if (i % 2 == 0) {
                ans[i] = ans[i/2];
            } else {
                ans[i] = ans[(i-1)/2] + 1;
            }
        }

        return ans;
    }
};
