class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int L = 0, R = 0;
        
        int maxFreq = 0;
        
        unordered_map<char, int>m;
        
        for (int i = 0; i < 26; i++) {
            m['A' + i] = 0;
        }
        
        while (R < s.size()) {
            m[s[R]]++;
            maxFreq = max(maxFreq, m[s[R]]);
            
            int w = R - L + 1;
            int requireStore = w - maxFreq;
            
            while (requireStore > k) {
                m[s[L]]--;
                L++;
                requireStore = R - L + 1 - maxFreq;
            }
            ans = max(ans, R - L + 1);
            R++;
        }
        
        return ans;
    }
};
