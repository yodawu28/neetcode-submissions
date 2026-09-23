class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> prefix;
        unordered_map<int, int>m;
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefix.push_back(sum);
        }

        int t;

        for (int i = 0; i < prefix.size(); i++) {
            t = prefix[i] - k;
            auto it = m.find(t);
            if (it != m.end()) {
                ans += m[t];
            }

            if (prefix[i] == k) {
                ans++;
            }

            it = m.find(prefix[i]);
            if (it == m.end()) {
                m.insert({prefix[i], 1});
            } else {
                m[prefix[i]]++;
            }
        }
        
        return ans;
    }
};