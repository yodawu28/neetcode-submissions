class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> pos;
        
        int L = 0, R = 0;
        
        while (R < s.size()) {
            auto it = pos.find(s[R]);
            if (it != pos.end()) {
                ans = max(ans, R - L);
                L = max(pos[s[R]] + 1, L);
            }
            pos[s[R]] = R;
            R++;
        }
        
        ans = max(ans, R - L);
        return ans;
    }
};
