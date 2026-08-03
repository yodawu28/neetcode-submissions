class Solution {
public:
    int climbStairs(int n) {
        // if (n == 1 || n == 2)
        // {
        //     return n;
        // }

        // return climbStairs(n-1) + climbStairs(n - 2);

        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);

        if (n <= 2)
        {
            return n;
        }

        for (int i = 3; i <= n; i++)
        {
            v.push_back(v[i-1] + v[i-2]);
        }

        return v[n];
    }
};
