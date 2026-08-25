class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    void run(string s, int start) {
        if (start >= s.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            string candidate = s.substr(start, i-start + 1);
            if (isPalindrome(candidate)) {
                curr.push_back(candidate);
                run(s, i+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        run(s, 0);

        return ans;
    }
};
