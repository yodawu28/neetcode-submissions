struct CompareByPriority {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        double a_len = a[0] * a[0] + a[1] * a[1];
        double b_len = b[0] * b[0] + b[1] * b[1];
        return a_len > b_len; // min heap by second
    }
};

class Solution {
public:
    priority_queue<vector<int>, vector<vector<int>>, CompareByPriority> pq; 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (int i = 0; i < points.size(); i++) {
            pq.push(points[i]);
        }   

        vector<vector<int>> ans;
        while (k > 0) {
            ans.push_back(pq.top());
            pq.pop();
            k--;
        } 

        return ans;
    }

    double getDistance(vector<int> v) {
        return 1.0 * v[0] * v[0] + v[1] * v[1];
    }
};
