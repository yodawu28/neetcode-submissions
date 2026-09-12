class Solution {
public:
    int getSign(int a, int b) {
        if (a < b) {
            return 1;
        } else if (a > b) {
            return 2;
        } else {
            return 0;
        }
    }

    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 0;
    
        if (arr.size() < 2) {
            return arr.size();
        }
        
        int L = 0, R = 1;
        int start = 0;
        int signs = -1;
        
        while (R < arr.size()) {
            int sign = getSign(arr[L], arr[R]);
            if (signs == -1) {
                if (sign == 0) {
                    ans = max(ans, R - start);
                    signs = -1;
                    start = R;
                } else {
                    signs = sign;
                }
            } else {
                if (sign == 0) {
                    ans = max(ans, R - start);
                    signs = -1;
                    start = R;
                } else if (sign == signs) {
                    ans = max(ans, R - start);
                    start = L;
                    signs = sign;
                } else {
                    signs = sign;
                }
            }
            
            L++;
            R++;
        }
        ans = max(ans, R - start);
        return ans;
    }
};