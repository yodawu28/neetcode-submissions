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
        vector<int> signs;
        
        while (R < arr.size()) {
            int sign = getSign(arr[L], arr[R]);
            if (signs.empty()) {
                if (sign == 0) {
                    ans = max(ans, R - start);
                    signs.clear();
                    start = R;
                } else {
                    signs.push_back(sign);
                }
            } else {
                if (sign == 0) {
                    ans = max(ans, R - start);
                    signs.clear();
                    start = R;
                } else if (sign == signs[signs.size()-1]) {
                    ans = max(ans, R - start);
                    start = L;
                    signs.push_back(sign);
                } else {
                    signs.push_back(sign);
                }
            }
            
            L++;
            R++;
        }
        ans = max(ans, R - start);
        return ans;
    }
};