class Solution {
public:
    vector<string> ans;
    string subset;
    void helper(vector<string> &letters, int k, int n, int idx) {
        if (subset.size() == k && k > 0) {
            ans.push_back(subset);
            return;
        }

        if (idx >= n) {
            return;
        }

        for (int j = idx; j < n; j++) {
            for (int i = 0; i < letters[idx].size(); i++) {
                subset.push_back(letters[j][i]);
                helper(letters, k, n, j+1);
                subset.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        ans.clear();
        subset.clear();

        unordered_map<char, string> keyboards = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };    

        vector<string> letters;
        for (char c: digits) {
            auto it = keyboards.find(c);
            if (it == keyboards.end()) {
                continue;
            }
            letters.push_back(keyboards[c]);
        }

        int k = digits.size();
        int n = letters.size();
        
        helper(letters, k, n, 0);
        
        return ans;
    }
};
