using pi = pair<int, int>;
using State = pair<int, pi>; // {distance, {x, y}}

int cal_distance(pi x, pi y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

string convert_to_key(pi x) {
    string key = to_string(x.first) + "-" + to_string(x.second);
    return key;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
    
        priority_queue<State, vector<State>, greater<State>> pq;
        unordered_set<string> visited;
        
        pi x = {points[0][0], points[0][1]};
        
        pq.push({0, x});
        
        while (!pq.empty()) {
            State top = pq.top();
            pq.pop();
            
            string key = convert_to_key(top.second);
            auto it2 = visited.find(key);
            if (it2 != visited.end()) {
                continue;
            }
            
            ans += top.first;
            visited.insert(key);
            
            for (int i = 0; i < points.size(); i++) {
                pi y = {points[i][0], points[i][1]};
                string key2 = convert_to_key(y);
                auto it = visited.find(key2);
                int dist = cal_distance(top.second, y);
                if (dist > 0 && it == visited.end()) {
                    pq.push({dist, y});
                }
            }
        }
        
        return ans;
    }
};
