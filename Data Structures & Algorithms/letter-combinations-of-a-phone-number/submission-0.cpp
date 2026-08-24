class Solution {
public:
    vector<string> ans;
    string curr = "";

    map<char, string>m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    void run(string digits, int idx) {
        if (idx > 0 && idx >= digits.size()) {
            ans.push_back(curr);
            return;
        }

        char t = digits[idx];
        for (int i = 0; i < m[t].size(); i++) {
            curr += m[t][i];
            run(digits, idx+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        run(digits, 0);

        return ans;
    }
};
