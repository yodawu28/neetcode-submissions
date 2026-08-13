class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;

        int lr = 0;
        int rr = m;
        
        int row = -1;
        int col = -1;
        
        while (lr <= rr) {
            int mid = lr + (rr - lr) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n]) {
                row = mid;
                break;
            } else if (matrix[mid][n] < target) {
                lr = mid + 1;
            } else {
                rr = mid - 1;
            }
        }
        
        if (row > -1) {
            int lc = 0;
            int rc = n;
            
            while (lc <= rc) {
                int mid = lc + (rc - lc) / 2;
                if (matrix[row][mid] == target) {
                    return true;
                } else if (target > matrix[row][mid]) {
                    lc = mid + 1;
                } else {
                    rc = mid - 1;
                }
            }
        }
        
        return false;
    }
};
