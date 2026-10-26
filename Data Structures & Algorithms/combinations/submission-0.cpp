class Solution {
public:
    vector<vector<int>> ans;
    vector<int>subset;

    void helper(int n, int k, int i) {
        if (subset.size() == k) {
            ans.push_back(subset);
            return;
        }

        if (i > n) {
            return;
        }

        // choose i
        subset.push_back(i);
        helper(n, k, i + 1);
        subset.pop_back();

        // not choose i
        helper(n, k, i + 1);
    }

    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        subset.clear();

        helper(n, k, 1);

        return ans;    
    }
};