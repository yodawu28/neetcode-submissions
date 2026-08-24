class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k = k;

        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() < _k) {
                pq.push(nums[i]);
            } else {
                if (pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < _k) {
            pq.push(val);
        } else {
            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};
