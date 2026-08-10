class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sortPoint(points, 0, points.size() - 1);

        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(points[i]);
        }

        return res;
    }

    vector<vector<int>> sortPoint(vector<vector<int>>& points, int s, int e) {
        if (s >= e) {
            return points;
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

        sortPoint(points, s, left - 1);
        sortPoint(points, left + 1, e);

        return points;
    }

    double get_distance(vector<int> v) {
        return sqrt(v[0] * v[0] + v[1] * v[1]);
    }
};
