class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        map<char, int> freq;
        priority_queue<int> maxFreq;
        int requireChange = 0;
        
        int L = 0, R = 0;

        for (int i = 0; i < 26; i++) {
            freq['A' + i] = 0;
        }
        
        while (R < s.size()) {
            freq[s[R]]++;
            maxFreq.push(freq[s[R]]);
            requireChange = R - L + 1 - maxFreq.top();
            while (requireChange > k) {
                ans = max(ans, R - L);
                int top = maxFreq.top();
                if (freq[s[L]] == top) {
                    maxFreq.pop();
                    freq[s[L]]--;
                    maxFreq.push(freq[s[L]]);
                } else {
                    freq[s[L]]--;
                }
                L++;
                requireChange = R - L + 1 - maxFreq.top();
            }
            R++;
        }
        ans = max(ans, R - L);
        return ans;
    }
};
