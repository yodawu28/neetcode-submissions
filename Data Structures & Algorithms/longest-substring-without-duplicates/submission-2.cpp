class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
    
        unordered_set<char> check;
        
        int L = 0, R = 0;
        
        while (R < s.size()) {
            auto it = check.find(s[R]);
            if (it == check.end()) {
                check.insert(s[R]);
                R++;
                continue;
            }
            
            ans = max(ans, R - L);
            
            int i = R - 1;
            while (i >= L) {
                if (s[i] == s[R]) {
                    L = i+1;
                    break;
                }
                i--;
            }
            R++;
        }
        
        ans = max(ans, R - L);
        return ans;
    }
};
