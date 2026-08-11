class Solution {
public:
    vector<vector<int>> res;

    void printDebug(vector<vector<int>>& points) {
        for (int i = 0; i < points.size(); i++) {
            printf("(%d, %d) ", points[i][0],  points[i][1]);
        }    
        cout << endl;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sortPoint(points, 0, points.size() - 1, k);
        printDebug(res);
        return res;
    }

    void sortPoint(vector<vector<int>>& points, int s, int e, int k) {
        int need = k - res.size();
        // cout << "need = " << need << endl;
        // cout << "partition size = " << e - s + 1 << endl;
        
        if (s > e || need == 0) {
            return;
        }

        int left = s;
        vector<int> pivot = points[e];

        for (int i = s; i <= e; i++)
        {
            if (get_distance(points[i]) < get_distance(pivot)) {
                vector<int> tmp = points[i];
                points[i] = points[left];
                points[left] = tmp;

                left++;
            }
        }
        
        points[e] = points[left];
        points[left] = pivot;
        
        // cout << "left: " << left << endl;
        // cout << "e: " << e << endl;
        // cout << "s: " << s << endl;
        // printDebug(points);
        
        if (left == s) {
            if (need > 0) {
                res.push_back(points[left]);
            }
            sortPoint(points, left + 1, e, k);
        } else if (left == e) {
            if (left - s <= need) {
                for (int i = s; i < left; i++) {
                    res.push_back(points[i]);
                }
            } 
            need = k - res.size();
            if (need) {
                sortPoint(points, s, left - 1, k);
            }
        } else {
            if (need >= (left - s)) {
                for (int i = s; i < left; i++) {
                    res.push_back(points[i]);
                }
                sortPoint(points, left, e, k);
            } else {
                sortPoint(points, s, left, k);
            }
        }
    }

    double get_distance(vector<int>& v) {
        return v[0] * v[0] + v[1] * v[1];
    }
};
