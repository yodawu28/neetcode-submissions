class KthLargest {
public:
    priority_queue<int> q;
    vector<int>v;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        _k = k;
    }
    
    int add(int val) {
        q.push(val);

        return getKth();
    }

    int getKth() {
        v.clear();
        int i = 0;
        while (i < _k && !q.empty()) {
            v.push_back(q.top());
            q.pop();
            i++;
        }

        for (int i = 0; i < v.size(); i++) {
            q.push(v[i]);
        }

        return v[_k - 1];
    }
};
