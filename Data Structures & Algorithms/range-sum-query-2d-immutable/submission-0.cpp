class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            prefix.push_back({});
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += matrix[i][j];
                prefix[i].push_back(sum);
            }
        }

        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += prefix[j][i];
                prefix[j][i] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int top = 0;
        if (row1 > 0) {
            top = prefix[row1 - 1][col2];
        }

        int left = 0;
        if (col1 > 0) {
            left = prefix[row2][col1-1];
        }

        int overlap = 0;
        if (row1 > 0 && col1 > 0) {
            overlap = prefix[row1 - 1][col1 - 1];
        }

        return prefix[row2][col2] - top - left + overlap;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */