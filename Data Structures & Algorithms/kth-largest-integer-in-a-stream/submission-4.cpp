class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        if (!nums.empty()) {
            make_heap(nums.begin(), nums.end());
        
            for (int i = 0; i < k && !nums.empty(); ++i) {
                std::pop_heap(nums.begin(), nums.end());
                pq.push(nums.back());
                nums.pop_back();
            }
        }
    }
    
    int add(int val) {
        if (pq.empty() || val > pq.top()) {
            if (pq.size() >= _k) {
                pq.pop();
            }
            pq.push(val);
        }

        return pq.top();
    }
};
