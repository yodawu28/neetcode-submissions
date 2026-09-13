class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = s.size() - 1;
        
        while (L < R) {
            s[L] = tolower(s[L]);
            s[R] = tolower(s[R]);
            
            if (!isalnum(s[L])) {
                L++;
                continue;
            }
            if (!isalnum(s[R])) {
                R--;
                continue;
            }
            
            if (s[L] != s[R]) {
                return false;
            }
            L++;
            R--;
        }
        return true;
    }
};
