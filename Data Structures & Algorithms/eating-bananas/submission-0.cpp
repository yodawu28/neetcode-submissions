class Solution {
public:
    int checkEat(int k, int h, vector<int>& piles) {
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] < k) {
                h--;
            } else {
                int t = piles[i] / k;
                if (piles[i] % k != 0) {
                    h--;
                }
                h -= t;
            }
        }
        
        if (h == 0) {
            return 0;
        } else if (h > 0) {
            return 1;
        } else {
            return -1;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1000000000;
        int ans = 1000000000;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int check = checkEat(mid, h, piles);
            if (check >= 0) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
