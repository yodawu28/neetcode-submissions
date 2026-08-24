class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        _k = k;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > _k) {
                pq.pop();   
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > _k) {
            pq.pop();
        } 

        return pq.top();
    }
};
