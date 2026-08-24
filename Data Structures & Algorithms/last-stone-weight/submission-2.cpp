class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        while (pq.size() >= 2) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            y = abs(y - x);
            pq.push(y);
        }

        return pq.top();
    }
};
