class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;

    void run(int n, int item, int k) {
        if (v.size() == k) {
            ans.push_back(v);
            return;
        }
        
        if (n - item + 1 < k - v.size()) {
            return;
        }
        
        // choose item
        v.push_back(item);
        run(n, item + 1, k);
        v.pop_back();
        
        // not choose
        run(n, item + 1, k);
    }

    vector<vector<int>> combine(int n, int k) {
        v.clear();
        ans.clear();
        run(n, 1, k);

        return ans;
    }
};
